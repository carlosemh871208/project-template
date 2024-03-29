/*********************************************************************************************************************/
/*                                                 PORT SOURCE CODE                                                  */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: Port.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-03-17 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \Port.c
    This module initializes the whole port structure of the microcontroller. Many ports and port pins can be assigned 
    to various functionalities like e.g.
    * General purpose I/O
    * ADC
    * SPI
    * SCI
    * PWM
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
#include "Port.h"
#include "std_types.h"
#include "stm32F401re.h"

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/*This shall changed according Microcontroller resources*/
static const uint32_t GPIOClkEnable[6] = {RCC_AHB1ENR_GPIOAEN,RCC_AHB1ENR_GPIOBEN,RCC_AHB1ENR_GPIOCEN,
                                   RCC_AHB1ENR_GPIODEN,RCC_AHB1ENR_GPIOEEN,RCC_AHB1ENR_GPIOHEN};
static GPIO_TypeDef* PORTCfg[6]  = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH}; 

/*                                             Port function definition                                              */
/*********************************************************************************************************************/
extern void Port_Init (const Port_ConfigType* ConfigPtr);
extern void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction);
extern void Port_RefreshPortDirection (void);
extern void Port_GetVersionInfo (Std_VersionInfoType* versioninfo);
extern void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode);

/*                                           Port function implementation                                            */
/*********************************************************************************************************************/
extern void Port_Init (const Port_ConfigType* ConfigPtr)
{
    /*Enable Clock using to RCC AHB1ENR*/
    RCC->AHB1ENR |= GPIOClkEnable[ConfigPtr->GPIOPortClkEn];
    /*Set default Port pin value*/
    PORTCfg[ConfigPtr->GPIOPortClkEn]->MODER |= ((ConfigPtr->PinDirection)<<(ConfigPtr->Pin<<1)); /*Set LED pin as output*/ 
}

extern void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction)
{
    
}

extern void Port_RefreshPortDirection (void)
{

}

extern void Port_GetVersionInfo (Std_VersionInfoType* versioninfo)
{

}

extern void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode)
{

}

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |    SAM-2    | 18-Aug-2022 | Port.c standard version.                                                    |
 *| CMARTI  |    SAM-4    | 22-Aug-2022 | Port.c functions implementation.                                            |
**********************************************************************************************************************/