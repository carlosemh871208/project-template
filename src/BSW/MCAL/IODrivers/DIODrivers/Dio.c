/*********************************************************************************************************************/
/*                                                 PORT SOURCE CODE                                                  */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: Dio.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-03-17 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \Dio.c
    This specification specifies the functionality, API and the configuration of the AUTOSAR Basic Software module 
    DIO Driver.
    This specification is applicable to drivers only for on chip DIO pins and ports.
    The DIO Driver provides services for reading and writing to/from
        * DIO Channels (Pins)
        * DIO Ports
    * DIO Channel Groups
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
#include "Dio.h"

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
static GPIO_TypeDef* PORTCfg[6]  = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH}; 

/*                                              Dio function definition                                              */
/*********************************************************************************************************************/
<<<<<<< HEAD
extern void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);

/*                                            Dio function implementation                                            */
/*********************************************************************************************************************/
extern void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    if(STD_LOW != Level)
    {
  
    }else
    {

    }
=======
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/*                                           Port function implementation                                            */
/*********************************************************************************************************************/
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{

>>>>>>> cdd7175 (SAM-5: Added function prototypes according Autosar)
}

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |    SAM-5    | 08-Sep-2022 | dio.c standard version.                                                    |
**********************************************************************************************************************/