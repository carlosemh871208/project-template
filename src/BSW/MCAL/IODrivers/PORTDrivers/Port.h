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

typedef struct 
{
    uint16 Pin;
    uint8  GPIOPortClkEn;
    uint8  PinDirection;
}Port_ConfigType;

/*
* Port_PinType
* Data type for the symbolic name of a port pin.
*/
typedef uint16 Port_PinType;

#define PA0 (Port_PinType)   0u
#define PA1 (Port_PinType)   1u
#define PA2 (Port_PinType)   2u
#define PA3 (Port_PinType)   3u
#define PA4 (Port_PinType)   4u
#define PA5 (Port_PinType)   5u
#define PA6 (Port_PinType)   6u
#define PA7 (Port_PinType)   7u
#define PA8 (Port_PinType)   8u
#define PA9 (Port_PinType)   9u
#define PA10 (Port_PinType) 10u
#define PA11 (Port_PinType) 11u
#define PA12 (Port_PinType) 12u

#define PB0 (Port_PinType)   0u
#define PB1 (Port_PinType)   1u
#define PB2 (Port_PinType)   2u
#define PB3 (Port_PinType)   3u
#define PB4 (Port_PinType)   4u
#define PB5 (Port_PinType)   5u
#define PB6 (Port_PinType)   6u
#define PB7 (Port_PinType)   7u
#define PB8 (Port_PinType)   8u
#define PB9 (Port_PinType)   9u
#define PB10 (Port_PinType) 10u
#define PB11 (Port_PinType) 11u
#define PB12 (Port_PinType) 12u

#define PC0 (Port_PinType)   0u
#define PC1 (Port_PinType)   1u
#define PC2 (Port_PinType)   2u
#define PC3 (Port_PinType)   3u
#define PC4 (Port_PinType)   4u
#define PC5 (Port_PinType)   5u
#define PC6 (Port_PinType)   6u
#define PC7 (Port_PinType)   7u
#define PC8 (Port_PinType)   8u
#define PC9 (Port_PinType)   9u
#define PC10 (Port_PinType) 10u
#define PC11 (Port_PinType) 11u
#define PC12 (Port_PinType) 12u

#define PD0 (Port_PinType)   0u
#define PD1 (Port_PinType)   1u
#define PD2 (Port_PinType)   2u
#define PD3 (Port_PinType)   3u
#define PD4 (Port_PinType)   4u
#define PD5 (Port_PinType)   5u
#define PD6 (Port_PinType)   6u
#define PD7 (Port_PinType)   7u
#define PD8 (Port_PinType)   8u
#define PD9 (Port_PinType)   9u
#define PD10 (Port_PinType) 10u
#define PD11 (Port_PinType) 11u
#define PD12 (Port_PinType) 12u

#define PE0 (Port_PinType)   0u
#define PE1 (Port_PinType)   1u
#define PE2 (Port_PinType)   2u
#define PE3 (Port_PinType)   3u
#define PE4 (Port_PinType)   4u
#define PE5 (Port_PinType)   5u
#define PE6 (Port_PinType)   6u
#define PE7 (Port_PinType)   7u
#define PE8 (Port_PinType)   8u
#define PE9 (Port_PinType)   9u
#define PE10 (Port_PinType) 10u
#define PE11 (Port_PinType) 11u
#define PE12 (Port_PinType) 12u

#define PH0 (Port_PinType)   0u
#define PH1 (Port_PinType)   1u
#define PH2 (Port_PinType)   2u
#define PH3 (Port_PinType)   3u
#define PH4 (Port_PinType)   4u
#define PH5 (Port_PinType)   5u
#define PH6 (Port_PinType)   6u
#define PH7 (Port_PinType)   7u
#define PH8 (Port_PinType)   8u
#define PH9 (Port_PinType)   9u
#define PH10 (Port_PinType) 10u
#define PH11 (Port_PinType) 11u
#define PH12 (Port_PinType) 12u

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
extern void Port_Init (const Port_ConfigType* ConfigPtr);

/*
* Port_SetPinDirection
* Sets the port pin direction
*/
extern void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction);

/*
* Port_RefreshPortDirection
* Refreshes port direction.
*/
extern void Port_RefreshPortDirection (void);

/*
* Port_GetVersionInfo
* Returns the version information of this module.
*/
extern void Port_GetVersionInfo (Std_VersionInfoType* versioninfo);

/*
* Port_SetPinMode
* Sets the port pin mode.
*/
extern void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode);

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |    SAM-2    | 18-Aug-2022 | First version of Port.h                                                     |
 *| CMARTI  |    SAM-3    | 22-Aug-2022 | Added PORTDriver autosar types                                              |
**********************************************************************************************************************/