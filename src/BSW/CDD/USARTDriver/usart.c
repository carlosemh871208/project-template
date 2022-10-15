/*********************************************************************************************************************/
/*                                                 PORT SOURCE CODE                                                  */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: usart.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-09-21 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \usart.c
    The universal synchronous asynchronous receiver transmitter (USART) offers a flexible means of full-duplex data 
    exchange with external equipment requiring an industry standard NRZ asynchronous serial data format. The USART 
    offers a very wide range of baud rates using a fractional baud rate generator.
    Steps for doing USART transmision:
        * Program the M bit in USART_CR1 to define the world lenght.
        * Program the number of stop bits in USART_CR2 register.
        * Select the desired baud rate using the USART_BRR register.
        * Set the TE bit in USART_CR1 to enable the transmit block .
        * Enable the USART by writing the UE bit in USART_CR1 register.
        * Now if txe flag is set, then write the data byte to send in the USART DR register.
        * After writing the last data into the USART_DR register, wait until TC=1.
    Steps for doing USART reception:
        * Program the M bit in USART_CR1 to define the world lenght.
        * Program the number of stop bits in USART_CR2 register.
        * Select the desired baud rate using the USART_BRR register.
        * Enable the USART by writing the UE bit in USART_CR1 register.
        * Set the RE bit in the USART_CR1 register, which enables the receiver block of the USART peripheral.
        * When a character is received, wait till the RXNE bit is set and read the data byte from the data register.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/

/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "usart.h"
#include "rcc.h"

/*                                                Constants and types                                                */
/*********************************************************************************************************************/


/*                                              Dio function definition                                              */
/*********************************************************************************************************************/
extern void  USART_Init(const USART_Config* pUSARTHandle);
extern void  USART_SetBaudRate(const USART_Config* pUSARTHandle);
extern uint8 USART_GetOversamplingMode(const USART_Config* pUSARTHandle);
extern void  USART_SendChar(char c);
extern uint8 USART_GetChar(void);

/* RCC depending functions */
extern uint8  RCC_GetSystemClockSource(void);
extern uint8  RCC_GetPLLClockSource(void);
extern uint32 RCC_GetSystemClockFrequency(void);
extern uint8  RCC_GetPLLPDivisorFactor(void);
extern uint16 RCC_GetPLLNMultiplicatorFactor(void);
extern uint8  RCC_GetPLLMDivisionFactor(void); 
extern uint32 RCC_GetFrequencyVCOClock(uint32 PLLClkInput);
extern uint32 RCC_GetPLL48ClockFrequency(void);
extern uint16 RCC_GetAHBClockDivisionFactor(void);
extern uint8  RCC_GetAPB1ClockDivisionFactor(void); 
extern uint8  RCC_GetAPB2ClockDivisionFactor(void); 

/*                                            Dio function implementation                                            */
/*********************************************************************************************************************/
/*
** Initialization USART function
*/
extern void USART_Init(const USART_Config* pUSARTHandle)
{
	/* Enable AHB1 peripheral clock */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //Enable GPIOA
	/* Configure pins as alternate functions */
	/* Configure TX */
	GPIOA->MODER &= ~(0b11<<22); // Clean previous pin configuration 
    GPIOA->MODER |=  (0b10<<22);   // Bits (5:4)= 1:0 --> Alternate Function for Pin PA11
	/* Configure RX */
	GPIOA->MODER &= ~(0b11<<24); // Clean previous pin configuration 
    GPIOA->MODER |=  (0b10<<24);   // Bits (7:6)= 1:0 --> Alternate Function for Pin PA12
	/* Configure GPIO AFR Alternate Function Register  */
	/* TX */
    GPIOA->AFR[1] &= ~(0b1111<<12); //Clean previous AFRH configuration
    GPIOA->AFR[1]  |= (0b1000<<12);   // Bites (11:10:9:8) = 0:1:1:1  --> AF7 Alternate function for USART2 at Pin PA11
	/* RX */
	GPIOA->AFR[1] &= ~(0b1111<<16); //Clean previous AFRH configuration
	GPIOA->AFR[1]  |= (0b1000<<16);   // Bites (15:14:13:12) = 0:1:1:1  --> AF7 Alternate function for USART2 at Pin PA12
    /* USART lines must be held high. So we need to pull_up resistors */
	/* TX */
	GPIOA->PUPDR &= ~(0b11<<22); //Clean previous configuration 
	GPIOA->PUPDR |=  (0b01<<22); //Set pull up resistor
	/* RX */
    GPIOA->PUPDR &= ~(0b11<<24); //Clean previous configuration 
	GPIOA->PUPDR |=  (0b01<<24); //Set pull up resistor
	/* Enable ABP1 peripheral clock */
	RCC->APB2ENR |= RCC_APB2ENR_USART6EN; //Enable USART2
	/*Configure USART*/
	/*
	 * Check startup code to see SysClock = 84 Mhz, AHB1 is working at 84 MHz and APB1 is working at 42 MHz
     * OVERSAMPLE 16
     * Baudrate 38400
     *
     * OVER8 sampling divider
     *      BaudRate = Fck/(16 * USARTDIV) .
     *      USARTDIV = DIV_Mantisa +(DIV_Fraction/ 8 x (2- OVER8))
     *      Fck = 16Mhz (default HSI)
     *
     * data width 8
     * parity None
     * stopbits 2
     * */
	/*  */
	USART6->CR1 &= ~(1<<15); /*Oversampling 16*/
	/*Configure Baudrate*/
	USART_SetBaudRate(pUSARTHandle);
	/* Enable RX and TX */
	USART6->CR1 |= (1<<2); // RE=1.. Enable the Receiver
	USART6->CR1 |= (1<<3);  // TE=1.. Enable Transmitter
	/* Configure word lenght */
	USART6->CR1 &= ~(1<<12); //Number of bits: 8 bits
	/* Configure Parity control*/
	USART6->CR1 &= ~(1<<10); // Parity control disable 
	/* Configure STOP bits */
	USART6->CR2 |= (2<<12); //Two stop bits 
	/* Configure RTS & CTS */
	USART6->CR3 &= ~(1<<8); //Disable RTS
	USART6->CR3 &= ~(1<<9); //Disable CTS
	/*Enable USART*/
	USART6->CR1 |= (1<<13);   // UE = 1... Enable USART
}

/*
**  USART Deinitialization: When CR1 UE is cleared, the USART prescalers and outputs are stopped and the end 
**                          of the current byte transfer in order to reduce power consumption. 
*/

/*
** Get Oversampling mode used by USART_SetBaudRate
*/
extern uint8 USART_GetOversamplingMode(const USART_Config* pUSARTHandle)
{
	return (uint8)((pUSARTHandle->USART_Port->CR1 & OVERSAMPMSK) >> OVERSAMPRSH);
}

/*
** USAR Baud rate configuration: Configures chosen baudrate.
*/
extern void  USART_SetBaudRate(const USART_Config* pUSARTHandle)
{
	uint32 FScrClk     = RCC_GetSystemClockFrequency();
	uint32 Denominador = 1u;
	uint32 Fraction    = 0u;
	uint16 Mantissa    = 0u;
	uint8  Over8       = USART_GetOversamplingMode(pUSARTHandle);
	Denominador = (8u*(2u-Over8)*pUSARTHandle->USART_Baud);
	pUSARTHandle->USART_Port->BRR &= ~(CLEANBRRREG);
	Mantissa = (uint16)(FScrClk/Denominador);
	Fraction = (uint32)(FScrClk - (Mantissa * Denominador));
	Fraction = (uint32)(Fraction * 10u)/Denominador;
	Fraction = (uint32)(Fraction * 16u)/10u;
	pUSARTHandle->USART_Port->BRR |= (Mantissa << MANTLSHIFT);
	pUSARTHandle->USART_Port->BRR |= ((uint8)Fraction << FRACLSHIFT);
}


/*
** USART send character: 
*/
void USART_SendChar (char c)
{
	/*********** STEPS FOLLOWED *************
	
	1. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
		 for each data to be transmitted in case of single buffer.
	2. After writing the last data into the USART_DR register, wait until TC=1. This indicates
		 that the transmission of the last frame is complete. This is required for instance when
		 the USART is disabled or enters the Halt mode to avoid corrupting the last transmission.
	
	****************************************/
	while (!(USART6->SR & (1<<7))); //Check when TXE bit is cleared that means TDR register has been transmitted into shift register.
	USART6->DR = (uint8)(c & 0xFFu);   // Load the Data
	while (!(USART6->SR & (1<<6)));  // Wait for TC to SET.. This indicates that the data has been transmitted
}


uint8 USART_GetChar (void)
{
		/*********** STEPS FOLLOWED *************
	
	1. Wait for the RXNE bit to set. It indicates that the data has been received and can be read.
	2. Read the data from USART_DR  Register. This also clears the RXNE bit
	
	****************************************/
	uint8 Temp;
	while (!(USART6->SR & (1<<5)));  // Wait for RXNE to SET.. This indicates that the data has been Received
	Temp = USART6->DR & 0xFF;  // Read the data. 
	return Temp;
}


extern uint8 RCC_GetSystemClockSource(void)
{
	uint8 SysClkSrc = SRCNOTAPP;
	if(HSISYSCLK == ((RCC->CFGR & SYSCLKMSK) >> SYSCLKSHR))
	{
        SysClkSrc = HSISYSCLK;
	}else if(HSESYSCLK == ((RCC->CFGR & SYSCLKMSK) >> SYSCLKSHR))
	{
        SysClkSrc = HSESYSCLK;
	}else if(PLLSYSCLK == ((RCC->CFGR & SYSCLKMSK) >> SYSCLKSHR))
	{
        SysClkSrc = PLLSYSCLK;
	}
	return SysClkSrc;
}

extern uint8 RCC_GetPLLClockSource(void)
{
	uint8 PllClkSrc = NOTDEFINED;
	if(HSISRCPLL == ((RCC->PLLCFGR & PLLSRCMSK) >> PLLSRCSHR))
	{
		PllClkSrc = HSISRCPLL;
	}else if(HSESRCPLL == ((RCC->PLLCFGR & PLLSRCMSK) >> PLLSRCSHR))
	{
		PllClkSrc = HSESRCPLL; 
	}
	return PllClkSrc;
}

extern uint32 RCC_GetSystemClockFrequency(void)
{
	uint32 SysClock = (uint32)NOTDEFINED;
	uint32 Fvco = 0u;
	uint8  PLLP = RCC_GetPLLPDivisorFactor();
	if(HSISYSCLK == RCC_GetSystemClockSource())
	{
        SysClock = HSICLKFREQ;
	}else if(HSESYSCLK == RCC_GetSystemClockSource())
	{
        SysClock = HSECLKFREQ;
	}else if(PLLSYSCLK == RCC_GetSystemClockSource())
	{
		if(HSISRCPLL == RCC_GetPLLClockSource())
		{
            Fvco = RCC_GetFrequencyVCOClock(HSICLKFREQ);
		}else if(HSESRCPLL == RCC_GetPLLClockSource())
		{
            Fvco = RCC_GetFrequencyVCOClock(HSECLKFREQ);
		}
		if(ZERODIV == PLLP)
		{
			SysClock = SYSCLKERR;
		}else if(ZERODIV != PLLP)
		{
			SysClock = (uint32) (Fvco/PLLP);
			if(SysClock > MAXMCUFREQ)
			{
				SysClock = SYSCLKERR;
			}else if(SysClock <= MAXMCUFREQ)
			{
				SysClock = SysClock & FREQCLKMSK;
			}
		}
	}
	return SysClock;
}

extern uint8  RCC_GetPLLPDivisorFactor(void)
{
    uint8 PLLP = (uint8)((RCC->PLLCFGR & PLLPMASK) >> PLLPRSHFT);
	if(PLLDIV2 == (PLLP & 0x3))
	{
        PLLP = PLLDIVVAL2;
	}else if(PLLDIV4 == (PLLP & 0x3))
	{
        PLLP = PLLDIVVAL4;
	}else if(PLLDIV6 == (PLLP & 0x3))
	{
        PLLP = PLLDIVVAL6;
	}else if(PLLDIV6 == (PLLP & 0x3))
	{
        PLLP = PLLDIVVAL8;
	}
	return PLLP;
}

extern uint16 RCC_GetPLLNMultiplicatorFactor(void)
{
	uint16 PLLN = (uint16)((RCC->PLLCFGR & PLLNMASK) >> PLLNRSHFT);
	if((0u <= (PLLN & PLLNFILTER)) && (192u > (PLLN & PLLNFILTER)))
	{
		PLLN = (uint16)PLLNWNGCFG;
	}else if((432u < (PLLN & PLLNFILTER)) && (511u >= (PLLN & PLLNFILTER)))
	{
		PLLN = (uint16)PLLNWNGCFG;
	}else if((192u <= (PLLN & PLLNFILTER)) && (432u >= (PLLN & PLLNFILTER)))
	{
		PLLN = (uint16)(PLLN & PLLNFILTER);
	}
	return PLLN;
}

extern uint8  RCC_GetPLLMDivisionFactor(void){
	uint8 PLLM = (uint8)((RCC->PLLCFGR & PLLMMASK) >> PLLMRSHFT);
	if((0u <= (PLLM & PLLMFILTER)) && (2u > (PLLM & PLLMFILTER)))
	{
		PLLM = (uint8)PLLMWNGCFG;

	}else if((2u <= (PLLM & PLLMFILTER)) && (63u >= (PLLM & PLLMFILTER)))
	{
		PLLM = (uint8)(PLLM & PLLMFILTER);
	}
	return PLLM;
}

extern uint8  RCC_GetPLLQDivisorFactor(void)
{
	uint8 PLLQ = (uint8)((RCC->PLLCFGR & PLLQMASK) >> PLLQRSHFT);
	if((0u <= (PLLQ & PLLQFILTER)) && (2u > (PLLQ & PLLQFILTER)))
	{
		PLLQ = (uint8)PLLQWNGCFG;

	}else if((2u <= (PLLQ & PLLQFILTER)) && (15u >= (PLLQ & PLLQFILTER)))
	{
		PLLQ = (uint8)(PLLQ & PLLQFILTER);
	}
	return PLLQ;
}

extern uint32  RCC_GetFrequencyVCOClock(uint32 PLLClkInput)
{
	uint32 FvcoClk = 0;
	uint16 PLLN = RCC_GetPLLNMultiplicatorFactor();
	uint8  PLLM = RCC_GetPLLMDivisionFactor();
	if((PLLNWNGCFG != PLLN) && (PLLMWNGCFG != PLLM) && (ZERODIV != PLLM))
	{
		FvcoClk = (uint32)(PLLClkInput * (PLLN/PLLM));
	}else if((PLLNWNGCFG == PLLN) && (PLLMWNGCFG == PLLM) && (ZERODIV == PLLM))
	{
		FvcoClk = (uint32)FVCOCLKWRG;
	}

	return FvcoClk;
}

extern uint32 RCC_GetPLL48ClockFrequency(void)
{
	uint32 Sys48Clk = (uint32)NOTDEFINED;
	uint32 Fvco = 0u;
	uint8  PLLQ = RCC_GetPLLQDivisorFactor();
	if(HSISYSCLK == RCC_GetSystemClockSource())
	{
        Sys48Clk = HSICLKFREQ;
	}else if(HSESYSCLK == RCC_GetSystemClockSource())
	{
        Sys48Clk = HSECLKFREQ;
	}else if(PLLSYSCLK == RCC_GetSystemClockSource())
	{
		if(HSISRCPLL == RCC_GetPLLClockSource())
		{
            Fvco = RCC_GetFrequencyVCOClock(HSICLKFREQ);
		}else if(HSESRCPLL == RCC_GetPLLClockSource())
		{
            Fvco = RCC_GetFrequencyVCOClock(HSECLKFREQ);
		}
		if(ZERODIV == PLLQ)
		{
			Sys48Clk = SYSCLKERR;
		}else if(ZERODIV != PLLQ)
		{
			Sys48Clk = (uint32) (Fvco/PLLQ);
			if(Sys48Clk > PLL48CLOCK)
			{
				Sys48Clk = SYSCLKERR;
			}else if(Sys48Clk <= PLL48CLOCK)
			{
				Sys48Clk = Sys48Clk & FREQCLKMSK;
			}
		}
	}
	return Sys48Clk;
}

extern uint16  RCC_GetAHBClockDivisionFactor(void)
{
	uint16 AHBprescaler = (uint16)((RCC->CFGR & AHBMASK) >> AHBRSHFT);
	if((0b0000u == AHBprescaler) || (0b0001u == AHBprescaler) || (0b0010u == AHBprescaler) || (0b0011u == AHBprescaler) ||
	   (0b0100u == AHBprescaler) || (0b0101u == AHBprescaler) || (0b0110u == AHBprescaler) || (0b0111u == AHBprescaler))
	{
		AHBprescaler = SYSCLKNDIV;
	}else if(0b1000u == AHBprescaler)
	{
		AHBprescaler = SYSCLKDIV2;
	}else if(0b1001u == AHBprescaler)
	{
		AHBprescaler = SYSCLKDIV4;
	}else if(0b1010u == AHBprescaler)
	{
		AHBprescaler = SYSCLKDIV8;
	}else if(0b1011u == AHBprescaler)
	{
		AHBprescaler = SYSCLKDIV16;
	}else if(0b1100u == AHBprescaler)
	{
		AHBprescaler = SYSCLKDIV64;
	}else if(0b1101u == AHBprescaler)
	{
		AHBprescaler = SYSCLKDIV128;
	}else if(0b1110u == AHBprescaler)
	{
		AHBprescaler = SYSCLKDIV256;
	}else if(0b1111u == AHBprescaler)
	{
		AHBprescaler = SYSCLKDIV512;
	}
	return (uint16)AHBprescaler;
}

extern uint8  RCC_GetAPB1ClockDivisionFactor(void)
{
	uint8 APB1prescaler = ((RCC->CFGR & APB1MASK) >> APB1RSHFT);
	if((0b000u == APB1prescaler) || (0b001u == APB1prescaler) || (0b010u == APB1prescaler) || (0b11u == APB1prescaler))
	{
		APB1prescaler = AHBNOTDIV;
	}else if(0b100u == APB1prescaler)
	{
		APB1prescaler = AHBDIVBY2;
	}else if(0b101u == APB1prescaler)
	{
		APB1prescaler = AHBDIVBY4;
	}else if(0b110u == APB1prescaler)
	{
		APB1prescaler = AHBDIVBY8;
	}else if(0b111u == APB1prescaler)
	{
		APB1prescaler = AHBDIVBY16;
	}
	return APB1prescaler;
}

extern uint8  RCC_GetAPB2ClockDivisionFactor(void)
{
	uint8 APB2prescaler = ((RCC->CFGR & APB2MASK) >> APB2RSHFT);
	if((0b000u == APB2prescaler) || (0b001u == APB2prescaler) || (0b010u == APB2prescaler) || (0b11u == APB2prescaler))
	{
		APB2prescaler = AHBNOTDIV;
	}else if(0b100u == APB2prescaler)
	{
		APB2prescaler = AHBDIVBY2;
	}else if(0b101u == APB2prescaler)
	{
		APB2prescaler = AHBDIVBY4;
	}else if(0b110u == APB2prescaler)
	{
		APB2prescaler = AHBDIVBY8;
	}else if(0b111u == APB2prescaler)
	{
		APB2prescaler = AHBDIVBY16;
	}
	return APB2prescaler;
}
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |             | 21-Sep-2022 | usart.c standard version.                                                   |
 *| CMARTI  |    SAM-7    | 22-Sep-2022 | USART driver implementation.                                                |
**********************************************************************************************************************/