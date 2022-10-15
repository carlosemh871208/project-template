/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: rcc.h $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-09-21 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \rcc.h
    Here we define types and function used by usart driver.
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
#include "std_types.h"
#include "stm32F401re.h"
/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/* CFGR register macros */
#define CFGRSWSMASK       0b11
#define SHIFTRSWS            2
#define HSI               0b00
#define HSE               0b01
#define PLL               0b10
#define CLOCK16MHZ    16000000
#define CLOCK8MHZ      8000000

#define CFGRHPREMASK       0xF
#define SHIFTRHPRE           4
#define SYSCLKNOTDIV         8
#define CLOCKONEDIV          1

#define CFGRPPRE1MASK      0x7
#define SHIFTRPPRE1         10 
#define AHBCLKNOTDIV         4
#define CFGRPPRE2MASK      0x7
#define SHIFTRPPRE2         13

/* RCC AHB1 Enable peripheral clock register macros */
#define AHB1GPIOA (uint32)RCC_AHB1ENR_GPIOAEN /* Mask to enable clock to GPIOA */
#define AHB1GPIOB (uint32)RCC_AHB1ENR_GPIOBEN /* Mask to enable clock to GPIOB */
#define AHB1GPIOC (uint32)RCC_AHB1ENR_GPIOCEN /* Mask to enable clock to GPIOB */
#define AHB1GPIOD (uint32)RCC_AHB1ENR_GPIODEN /* Mask to enable clock to GPIOD */
#define AHB1GPIOE (uint32)RCC_AHB1ENR_GPIOEEN /* Mask to enable clock to GPIOE */
#define AHB1GPIOH (uint32)RCC_AHB1ENR_GPIOHEN /* Mask to enable clock to GPIOH */
#define AHB1CRC   (uint32)RCC_AHB1ENR_CRCEN   /* Mask to enable clock to CRC */
#define AHB1DMA1  (uint32)RCC_AHB1ENR_DMA1EN  /* Mask to enable clock to DMA1 */
#define AHB1DMA2  (uint32)RCC_AHB1ENR_DMA2EN  /* Mask to enable clock to DMA2 */

/* Status register macros */
#define DISABLE (uint8)0u
#define ENABLE  (uint8)1u

/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/
extern uint32 RCC_GetPCLK1Value(void);
extern uint32 RCC_GetPCLK2Value(void);
extern uint32 RCC_GetPLLOutputClock(void);
extern void   RCC_AHB1PeripheralClockControl(uint32 peripheral,uint8 status);
extern uint8  RCC_GetClkAHB1PeripheralSts(uint32 peripheral);

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |             | 23-Sep-2022 | First version of rcc.h                                                      |
**********************************************************************************************************************/