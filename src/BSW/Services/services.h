/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: delayServices.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-08-17 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \services.h
    Here we define interfaces that connect services layer with RTE layer.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef SERVICES_H_
#define SERVICES_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "std_types.h"
#include "delayServices.h"

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/
/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/
#define Services_delay_mS(uint16) delay_mS(uint16)

#endif /* SERVICES_H_ */

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |     NA      | 17-Aug-2022 | First version of services.h                                                 |
**********************************************************************************************************************/
