/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: main.c $
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

//* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
*/
#ifndef __I0
    #define __IO volatile /*Define read/write permissions*/
#endif

#ifndef __I
    #define __I volatile const /*Define read only permissions*/
#endif

#ifndef __O
    #define __O volatile /*Define write only permissions*/
#endif


/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/

#endif /* STD_TYPES_H_ */

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |     NA      | 28-Apr-2021 | First version of Std_Types.h                                                |
**********************************************************************************************************************/
