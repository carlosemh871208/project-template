/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: mcu_sdk.h $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-10-15 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \mcu_sdk.h
    HProvide Microcontroller Low Level drivers and datatypes ready to be used on AUTOSAR architecture.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef MCU_SDK_H_
#define MCU_SDK_H_

/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "rcc.h"

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/*
** RCC peripheral constants
*/
/*System clock sources*/
#define MCU_SDK_HSISYSCLK   HSISYSCLK        /* If 0b00u is selected System clock source is HSI */
#define MCU_SDK_HSESYSCLK   HSESYSCLK        /* If 0b01u is selected System clock source is HSE */
#define MCU_SDK_PLLSYSCLK   PLLSYSCLK        /* If 0b10u is selected System clock source is PLL */
#define MCU_SDK_SRCNOTAPP   SRCNOTAPP        /* If 0b11u is selected System clock source not applicable */
/* End of RCC peripheral constants */

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/
/*
** RCC peripheral functions
*/
#define MCU_SDK_RCC_GetSystemClockSource(void)                  RCC_GetSystemClockSource(void)
#define MCU_SDK_RCC_GetPLLClockSource(void);                    RCC_GetPLLClockSource(void); 
#define MCU_SDK_RCC_GetSystemClockFrequency(void);              RCC_GetSystemClockFrequency(void); 
#define MCU_SDK_RCC_GetPLLPDivisorFactor(void);                 RCC_GetPLLPDivisorFactor(void);          
#define MCU_SDK_RCC_GetPLLNMultiplicatorFactor(void);           RCC_GetPLLNMultiplicatorFactor(void);    
#define MCU_SDK_RCC_GetPLLMDivisionFactor(void);                RCC_GetPLLMDivisionFactor(void); 
#define MCU_SDK_RCC_GetPLL48ClockFrequency(void);               RCC_GetPLL48ClockFrequency(void); 
#define MCU_SDK_RCC_GetAHBClockDivisionFactor(void);            RCC_GetAHBClockDivisionFactor(void); 
#define MCU_SDK_RCC_GetAPB1ClockDivisionFactor(void);           RCC_GetAPB1ClockDivisionFactor(void);
#define MCU_SDK_RCC_GetAPB2ClockDivisionFactor(void);           RCC_GetAPB2ClockDivisionFactor(void); 
/*End of RCC peripheral functions*/

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |    SAM-9    | 15-Oct-2022 | First version of mcu_sdk.h                                                  |
**********************************************************************************************************************/