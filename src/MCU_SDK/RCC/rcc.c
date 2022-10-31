/*********************************************************************************************************************/
/*                                                 PORT SOURCE CODE                                                  */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: rcc.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-03-17 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \rcc.c
    This module provides rcc dirver and types for Reset & clock control.
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
#include "rcc.h"

/*                                                Constants and types                                                */
/*********************************************************************************************************************/

/*                                             Port function definition                                              */
/*********************************************************************************************************************/
extern uint8  RCC_GetSystemClockSource(void);               /* Return System Clock source */
extern uint8  RCC_GetPLLClockSource(void);                  /* Return PLL clock source */
extern uint32 RCC_GetSystemClockFrequency(void);            /* Return System clock frequency */
extern uint8  RCC_GetPLLPDivisorFactor(void);               /* Return PLLP divisot factor */
extern uint16 RCC_GetPLLNMultiplicatorFactor(void);         /* Return PLLN multiplicator factor */
extern uint8  RCC_GetPLLMDivisionFactor(void);              /* Return PLLM division factor */
extern uint32 RCC_GetPLL48ClockFrequency(void);             /* Return PLL48 clock frequency */
extern uint16 RCC_GetAHBClockDivisionFactor(void);          /* Return AHB clock division factor */
extern uint8  RCC_GetAPB1ClockDivisionFactor(void);         /* Return APB1 clock division factor */
extern uint8  RCC_GetAPB2ClockDivisionFactor(void);         /* Return APB2 clock division factor */

static uint32 RCC_GetFrequencyVCOClock(uint32 PLLClkInput); /* Return VCO clock frequency */

/*                                           Port function implementation                                            */
/*********************************************************************************************************************/
/* 
** Return System Clock source 
*/
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

/* 
** Return PLL clock source
*/
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

/* 
** Return System clock frequency
*/
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

/* 
** Return PLLP divisot factor 
*/
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

/* 
** Return PLLN multiplicator factor 
*/
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

/* 
** Return PLLM division factor 
*/
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

/* 
** Return PLLQ divisor factor
*/
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

/* 
** Return PLL48 clock frequency 
*/
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

/* 
** Return AHB clock division factor 
*/
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

/* 
** Return APB1 clock division factor 
*/
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

/* 
** Return APB2 clock division factor 
*/
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

/* 
** Return VCO clock frequency
*/
static uint32  RCC_GetFrequencyVCOClock(uint32 PLLClkInput)
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
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |    SAM-9    | 15-Oct-2022 | rcc.c standard version.                                                     |
**********************************************************************************************************************/