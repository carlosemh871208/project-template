/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: Dio.h $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-08-19 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \Dio.h
    Here we define types and function used by port driver.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "std_types.h"
#include "stm32F401re.h"
/*                                                Constants and types                                                */
/*********************************************************************************************************************/
typedef unsigned char Dio_LevelType;
typedef unsigned int Dio_ChannelType;

#define PA0 (Dio_ChannelType)   0u
#define PA1 (Dio_ChannelType)   1u
#define PA2 (Dio_ChannelType)   2u
#define PA3 (Dio_ChannelType)   3u
#define PA4 (Dio_ChannelType)   4u
#define PA5 (Dio_ChannelType)   5u
#define PA6 (Dio_ChannelType)   6u
#define PA7 (Dio_ChannelType)   7u
#define PA8 (Dio_ChannelType)   8u
#define PA9 (Dio_ChannelType)   9u
#define PA10 (Dio_ChannelType) 10u
#define PA11 (Dio_ChannelType) 11u
#define PA12 (Dio_ChannelType) 12u

#define PB0 (Dio_ChannelType)   0u
#define PB1 (Dio_ChannelType)   1u
#define PB2 (Dio_ChannelType)   2u
#define PB3 (Dio_ChannelType)   3u
#define PB4 (Dio_ChannelType)   4u
#define PB5 (Dio_ChannelType)   5u
#define PB6 (Dio_ChannelType)   6u
#define PB7 (Dio_ChannelType)   7u
#define PB8 (Dio_ChannelType)   8u
#define PB9 (Dio_ChannelType)   9u
#define PB10 (Dio_ChannelType) 10u
#define PB11 (Dio_ChannelType) 11u
#define PB12 (Dio_ChannelType) 12u

#define PC0 (Dio_ChannelType)   0u
#define PC1 (Dio_ChannelType)   1u
#define PC2 (Dio_ChannelType)   2u
#define PC3 (Dio_ChannelType)   3u
#define PC4 (Dio_ChannelType)   4u
#define PC5 (Dio_ChannelType)   5u
#define PC6 (Dio_ChannelType)   6u
#define PC7 (Dio_ChannelType)   7u
#define PC8 (Dio_ChannelType)   8u
#define PC9 (Dio_ChannelType)   9u
#define PC10 (Dio_ChannelType) 10u
#define PC11 (Dio_ChannelType) 11u
#define PC12 (Dio_ChannelType) 12u

#define PD0 (Dio_ChannelType)   0u
#define PD1 (Dio_ChannelType)   1u
#define PD2 (Dio_ChannelType)   2u
#define PD3 (Dio_ChannelType)   3u
#define PD4 (Dio_ChannelType)   4u
#define PD5 (Dio_ChannelType)   5u
#define PD6 (Dio_ChannelType)   6u
#define PD7 (Dio_ChannelType)   7u
#define PD8 (Dio_ChannelType)   8u
#define PD9 (Dio_ChannelType)   9u
#define PD10 (Dio_ChannelType) 10u
#define PD11 (Dio_ChannelType) 11u
#define PD12 (Dio_ChannelType) 12u

#define PE0 (Dio_ChannelType)   0u
#define PE1 (Dio_ChannelType)   1u
#define PE2 (Dio_ChannelType)   2u
#define PE3 (Dio_ChannelType)   3u
#define PE4 (Dio_ChannelType)   4u
#define PE5 (Dio_ChannelType)   5u
#define PE6 (Dio_ChannelType)   6u
#define PE7 (Dio_ChannelType)   7u
#define PE8 (Dio_ChannelType)   8u
#define PE9 (Dio_ChannelType)   9u
#define PE10 (Dio_ChannelType) 10u
#define PE11 (Dio_ChannelType) 11u
#define PE12 (Dio_ChannelType) 12u

#define PH0 (Dio_ChannelType)   0u
#define PH1 (Dio_ChannelType)   1u
#define PH2 (Dio_ChannelType)   2u
#define PH3 (Dio_ChannelType)   3u
#define PH4 (Dio_ChannelType)   4u
#define PH5 (Dio_ChannelType)   5u
#define PH6 (Dio_ChannelType)   6u
#define PH7 (Dio_ChannelType)   7u
#define PH8 (Dio_ChannelType)   8u
#define PH9 (Dio_ChannelType)   9u
#define PH10 (Dio_ChannelType) 10u
#define PH11 (Dio_ChannelType) 11u
#define PH12 (Dio_ChannelType) 12u

typedef unsigned int Dio_LevelType;
typedef unsigned int Dio_ChannelType;

#define STD_LOW		0x00
#define STD_HIGH	0x01
/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/
extern void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |    SAM-5    | 08-Sep-2022 | First version of Dio.h                                                      |
 *| CMARTI  |    SAM-5    | 08-Sep-2022 | Added function prototypes according autosar                                 |
**********************************************************************************************************************/