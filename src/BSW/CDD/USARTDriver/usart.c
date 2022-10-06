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
extern void  USART_DeInit(const USART_Config* pUSARTHandle);
extern void  USART_SendData (const USART_Config* pUSARTHandle, uint8* pTxBuffer, uint32 Lenght);
extern void  USART_ReceiveData (const USART_Config* pUSARTHandle, uint8* pRxBuffer, uint32 Lenght);
extern void  USART_SetBaudRate(const USART_Config* pUSARTHandle);
extern void  USART_PeriClockControl(const USART_Config* pUSARTHandle, uint8 EnorDi);
extern void  USART_PeripheralControl(const USART_Config* pUSARTHandle, uint8 EnOrDi);
extern uint8 USART_GetFlagStatus(const USART_Config* pUSARTHandle, uint8 StatusFlagName);
extern void  USART_SendChar(char c);
extern uint8 USART_GetChar(void);

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
	USART6->BRR &= ~(0xFFFF); // Clear the mantisa and fraction
	USART6->BRR |= (136<<4); // Mantisa
	USART6->BRR |= (12<<0); //  Fraction
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
extern void USART_DeInit(const USART_Config* pUSARTHandle)
{
	
}

/*
**  Send Data string
*/
extern void USART_SendData (const USART_Config* pUSARTHandle, uint8* pTxBuffer, uint32 Lenght)
{
	
}

/*
** Receive data string
*/
extern void USART_ReceiveData (const USART_Config* pUSARTHandle, uint8* pRxBuffer, uint32 Lenght)
{
	
}

/*
** Set Baud rate
*/
extern void USART_SetBaudRate(const USART_Config* pUSARTHandle)
{
   
}

/*
** Enable the Clock for given USART peripheral
*/
extern void USART_PeriClockControl(const USART_Config* pUSARTHandle, uint8 EnorDi)
{
	
}

extern void USART_PeripheralControl (const USART_Config* pUSARTHandle, uint8 EnOrDi)
{
	
}

 
 /*
 **
 */
extern uint8 USART_GetFlagStatus(const USART_Config* pUSARTHandle, uint8 StatusFlagName)
{
	return 0u;
}

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
	
	while (!(USART2->SR & (1<<5)));  // Wait for RXNE to SET.. This indicates that the data has been Received
	Temp = USART2->DR & 0xFF;  // Read the data. 
	return Temp;
}

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |             | 21-Sep-2022 | usart.c standard version.                                                   |
 *| CMARTI  |    SAM-7    | 22-Sep-2022 | USART driver implementation.                                                |
**********************************************************************************************************************/