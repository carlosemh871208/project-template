/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: Port.h $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-08-19 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \Port.h
    Here we define types and function used by port driver.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef PORT_H_
#define PORT_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "std_types.h"
#include "stm32F401re.h"
/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/*
* Port_ConfigType
* Type of the external data structure containing the initialization data for this module.
* The contents of the initialization data structure are specific to the microcontroller.
*/
#define PORTA 0u
#define PORTB 1u
#define PORTC 2u
#define PORTD 3u
#define PORTE 4u
#define PORTH 5u

const uint32_t RCCAHB1ENRGPIOMask[6] = {RCC_AHB1ENR_GPIOAEN,RCC_AHB1ENR_GPIOBEN,RCC_AHB1ENR_GPIOCEN,RCC_AHB1ENR_GPIODEN
                                        RCC_AHB1ENR_GPIOEEN,RCC_AHB1ENR_GPIOHEN};
typedef struct 
{
    RCC_TypeDef*  GPIOPortClkEn;
    GPIO_TypeDef* GPIOPortPinCfg[6] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};
}Port_ConfigType;

/*
* Port_PinType
* Data type for the symbolic name of a port pin.
*/
typedef uint16 Port_PinType;

/*
* Port_PinDirectionType
* Possible directions of a port pin.
*/
typedef uint8 Port_PinDirectionType;
#define PORT_PIN_IN  ((Port_PinDirectionType)0x00u) /*Sets port pin as input.*/
#define PORT_PIN_OUT ((Port_PinDirectionType)0x01u) /*Sets port pin as output.*/

/*
* Port_PinModeType
* Different port pin modes.
* As several port pin modes shall be configurable on one pin, the range shall be determined by the implementation.
*/
typedef uint32 Port_PinModeType;

/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/
/*
* Port_Init
* Initializes the Port Driver module.
*/
void Port_Init (const Port_ConfigType* ConfigPtr);

/*
* Port_SetPinDirection
* Sets the port pin direction
*/
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction);

/*
* Port_RefreshPortDirection
* Refreshes port direction.
*/
void Port_RefreshPortDirection (void);

/*
* Port_GetVersionInfo
* Returns the version information of this module.
*/
void Port_GetVersionInfo (Std_VersionInfoType* versioninfo);

/*
* Port_SetPinMode
* Sets the port pin mode.
*/
void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode);

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |    SAM-2    | 18-Aug-2022 | First version of Port.h                                                     |
 *| CMARTI  |    SAM-3    | 22-Aug-2022 | Added PORTDriver autosar types                                              |
**********************************************************************************************************************/