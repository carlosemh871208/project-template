/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: std_types.h $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-03-02 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \std_Types.h
    Here we define all data types required by the project.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/*Byte types definition*/
typedef unsigned char  uint8;
typedef signed   char  sint8;

/*Word types definition*/
typedef unsigned short uint16;
typedef signed   short sint16;

/*Long types definition*/
typedef unsigned long  uint32;
typedef signed   long  sint32;

/*Boolean type definition*/
typedef uint8 boolean;

#define FALSE (boolean)0u
#define TRUE  (boolean)1u

/*Null type definition*/
#ifndef NULL
    #define NULL (void*) 0u
#endif

/*Exit Program*/
#define EXIT_PROGRAM (boolean) 0u

/*Symbol definitions*/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
typedef unsigned char StatusType; /*OSEK compliance*/
#define E_OK       0x00u
#endif
#define E_NOT_OK   0x01u

#define STD_HIGH   0x01u /* Physical state 5V or 3.3V */ 
#define STD_LOW    0x00u /* Physical state 0V */

#define STD_ACTIVE 0x01u /* #define STD_IDLE 0x00u */
#define STD_IDLE   0x00u /* Logical state idle */

#define STD_OFF    0x00u
#define STD_ON     0x01u

/*
* Std_ReturnType
* This type can be used as standard API return type which is shared between the RTE and the BSW modules. It shall be 
* defined as follows: typedef uint8 Std_ReturnType;
*/
typedef uint8 Std_ReturnType;

/*
* Std_VersionInfoType
* This type shall be used to request the version of a BSW module using the <Module name>_GetVersionInfo() function.
*/
typedef struct
{
    /* data */
    uint16 vendorID;
    uint16 moduleID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
}Std_VersionInfoType;

/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/

#endif /* STD_TYPES_H_ */

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |     NA      | 28-Apr-2021 | First version of Std_Types.h                                                |
**********************************************************************************************************************/
