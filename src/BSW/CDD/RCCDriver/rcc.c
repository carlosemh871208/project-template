/*********************************************************************************************************************/
/*                                                 PORT SOURCE CODE                                                  */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: rcc.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-09-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \rcc.c
    Reset and clock control (RCC).
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
const uint16 AHB_PreScaler[8]  = {2,4,8,16,64,128,256,512};
const uint8  APB1_PreScaler[4] = {2,4,8,16};

/*                                              Dio function definition                                              */
/*********************************************************************************************************************/
extern uint32 RCC_GetPCLK1Value(void);
extern uint32 RCC_GetPCLK2Value(void);
extern uint32 RCC_GetPLLOutputClock(void);
extern void   RCC_AHB1PeripheralClockControl(uint32 peripheral,uint8 status);
extern uint8  RCC_GetClkAHB1PeripheralSts(uint32 peripheral);

/*                                            Dio function implementation                                            */
/*********************************************************************************************************************/
extern uint32 RCC_GetPCLK1Value(void)
{
    uint32 pclk1;
    uint32 SystemClk;
	uint8  clksrc;
    uint8  hprb;
    uint8  ppre1;
    uint8  ahbp;
    uint8  apb1p;

    /* Check which clock source is used as the system clock */
	clksrc = (uint32)((RCC->CFGR >> SHIFTRSWS) & CFGRSWSMASK);
	if(HSI == clksrc)
	{
		SystemClk = CLOCK16MHZ;
	}else if(HSE == clksrc)
	{
		SystemClk = CLOCK8MHZ;
	}else if (PLL == clksrc)
	{
		SystemClk = RCC_GetPLLOutputClock();
	}

	/* Set control AHB clock division factor */
	hprb = (uint32)((RCC->CFGR >> SHIFTRHPRE) & CFGRHPREMASK);
	if(SYSCLKNOTDIV > hprb)
	{
		ahbp = (uint8)CLOCKONEDIV;
	}else
	{
		ahbp = AHB_PreScaler[hprb-SYSCLKNOTDIV];
	}

	/* Set control APB1 low-speed clock division factor */
	ppre1 = ((RCC->CFGR >> SHIFTRPPRE1) & CFGRPPRE1MASK);
	if(AHBCLKNOTDIV > ppre1)
	{
		apb1p = (uint8)CLOCKONEDIV;
	}else
	{
		apb1p = APB1_PreScaler[ppre1-AHBCLKNOTDIV];
	}

    /* Return APB1 clock */
	pclk1 = (uint32)(SystemClk/ahbp)/apb1p;
	return pclk1;
}

extern uint32 RCC_GetPCLK2Value(void)
{
    uint32 pclk2;
    uint32 SystemClk;
	uint8  clksrc;
    uint8  hprb;
    uint8  ppre2;
    uint8  ahbp;
    uint8  apb2p;

    /* Check which clock source is used as the system clock */
    clksrc = (uint32)((RCC->CFGR >> SHIFTRSWS) & CFGRSWSMASK);
    if(HSI == clksrc)
	{
		SystemClk = CLOCK16MHZ;
	}else if(HSE == clksrc)
	{
		SystemClk = CLOCK8MHZ;
	}else if (PLL == clksrc)
	{
		SystemClk = RCC_GetPLLOutputClock();
	}

    /* Set control AHB clock division factor */
	hprb = (uint32)((RCC->CFGR >> SHIFTRHPRE) & CFGRHPREMASK);
	if(SYSCLKNOTDIV > hprb)
	{
		ahbp = (uint8)CLOCKONEDIV;
	}else
	{
		ahbp = AHB_PreScaler[hprb-SYSCLKNOTDIV];
	}

    /* Set control APB2 low-speed clock division factor */
	ppre2 = ((RCC->CFGR >> SHIFTRPPRE2) & CFGRPPRE2MASK);
	if(AHBCLKNOTDIV > ppre2)
	{
		apb2p = (uint8)CLOCKONEDIV;
	}else
	{
		apb2p = APB1_PreScaler[ppre2-AHBCLKNOTDIV];
	}    

    /* Return APB1 clock */
	pclk2 = (uint32)(SystemClk/ahbp)/apb2p;
	return pclk2;
}

extern uint32 RCC_GetPLLOutputClock(void)
{
    return 0;
}

/*
** This function Enable Clock to AHB1 peripheral
*/
extern void   RCC_AHB1PeripheralClockControl(uint32 peripheral, uint8 status)
{
	if(ENABLE == status)
	{
		RCC->AHB1ENR |= peripheral;
	} else if(DISABLE == status)
	{
	    RCC->AHB1ENR &= ~peripheral;
	}
}

/*
** This function returns if Clock to AHB1 is enable
*/
extern uint8  RCC_GetClkAHB1PeripheralSts(uint32 peripheral)
{
	uint8 perStatus = DISABLE;
	if(!(peripheral & RCC->AHB1ENR))
	{
		perStatus = ENABLE;
	}
	return perStatus;
}

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |             | 23-Sep-2022 | rcc.c standard version.                                                     |
**********************************************************************************************************************/