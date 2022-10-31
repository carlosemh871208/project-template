/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: rcc.h $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-10-15 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \rcc.h
    Low level driver and types for Reset and clock Control
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef RCC_H_
#define RCC_H_

/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "stm32F401re.h"

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
#define NOTDEFINED 0x00u         

#define HSICLKFREQ 16000000u     /* Check values provided by Microcontroller user manual */
#define HSECLKFREQ 20000000u     /* Check value from external oscillator */
#define MAXMCUFREQ 84000000u     /* Check values provided by Microcontroller user manual */
#define PLL48CLOCK 48000000u     /* Check values provided by Microcontroller user manual */

/*System clock sources*/
#define HSISYSCLK  0b00u         /* If 0b00u is selected System clock source is HSI */
#define HSESYSCLK  0b01u         /* If 0b01u is selected System clock source is HSE */
#define PLLSYSCLK  0b10u         /* If 0b10u is selected System clock source is PLL */
#define SRCNOTAPP  0b11u         /* If 0b11u is selected System clock source not applicable */

#define SYSCLKMSK  0xCu          /* System clock mask */
#define SYSCLKSHR  2u            /* Shift 2 positions to right*/
#define SYSCLKERR  0xFFFFFFFFu   /* System Clock error */

#define PLLNMASK   0x7FC0u        
#define PLLNRSHFT  6u
#define PLLPMASK   0x30000u
#define PLLPRSHFT  16u
#define PLLMMASK   0x3Fu
#define PLLMRSHFT  0u
#define PLLQMASK   0xF000000u
#define PLLQRSHFT  24u

#define PLLDIV2    0b00u
#define PLLDIV4    0b01u
#define PLLDIV6    0b10u
#define PLLDIV8    0b11u

#define PLLDIVVAL2 2u
#define PLLDIVVAL4 4u
#define PLLDIVVAL6 6u
#define PLLDIVVAL8 8u

#define PLLNWNGCFG 0xFFFFu
#define PLLNFILTER 0x1FFu

#define PLLMWNGCFG 0xFFu
#define PLLMFILTER 0x3Fu

#define PLLQWNGCFG 0xFFu
#define PLLQFILTER 0xFu

/* PLL clock sources*/
#define HSISRCPLL  0u
#define HSESRCPLL  1u

#define PLLSRCMSK  0x400000  
#define PLLSRCSHR  22u

#define ZERODIV    0u

#define FVCOCLKWRG  0xFFFFFFFFu

#define FREQCLKMSK  0x1FFFFFFFu
#define FQ48CLKMSK  0x3FFFFFFu

/*AHB prescaler*/
#define AHBMASK     0xF0u
#define AHBRSHFT    4u

#define SYSCLKNDIV    1u
#define SYSCLKDIV2    2u
#define SYSCLKDIV4    4u
#define SYSCLKDIV8    8u
#define SYSCLKDIV16   16u
#define SYSCLKDIV64   64u
#define SYSCLKDIV128  128u
#define SYSCLKDIV256  256u
#define SYSCLKDIV512  512u

/* APB1 prescaler */
#define APB1MASK      0x1C00u
#define APB1RSHFT     10u

/* APB2 prescaler */
#define APB2MASK      0xE000u
#define APB2RSHFT     13u

#define AHBNOTDIV     1u
#define AHBDIVBY2     2u
#define AHBDIVBY4     4u
#define AHBDIVBY8     8u
#define AHBDIVBY16    16u

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
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

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |    SAM-9    | 15-Oct-2022 | First version of rcc.h                                                      |
**********************************************************************************************************************/