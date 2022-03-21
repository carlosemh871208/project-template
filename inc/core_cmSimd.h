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
#if   defined ( __ICCARM__ )
 #pragma system_include         /* treat file as system include file for MISRA check */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang system_header   /* treat file as system include file */
#endif

#ifndef CORE_CMSIMD_H_
#define CORE_CMSIMD_H_

#ifdef __cplusplus
 extern "C" {
#endif

/*                                                       Includes                                                    */
/*********************************************************************************************************************/

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/*------------------ RealView Compiler -----------------*/
#if   defined ( __CC_ARM )
  #include "cmsis_armcc.h"

/*------------------ ARM Compiler V6 -------------------*/
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #include "cmsis_armcc_V6.h"

/*------------------ GNU Compiler ----------------------*/
#elif defined ( __GNUC__ )
  #include "cmsis_gcc.h"

/*------------------ ICC Compiler ----------------------*/
#elif defined ( __ICCARM__ )
  #include <cmsis_iar.h>

/*------------------ TI CCS Compiler -------------------*/
#elif defined ( __TMS470__ )
  #include <cmsis_ccs.h>

/*------------------ TASKING Compiler ------------------*/
#elif defined ( __TASKING__ )
  /*
   * The CMSIS functions have been implemented as intrinsics in the compiler.
   * Please use "carm -?i" to get an up to date list of all intrinsics,
   * Including the CMSIS ones.
   */

/*------------------ COSMIC Compiler -------------------*/
#elif defined ( __CSMC__ )
  #include <cmsis_csm.h>

#endif

/*@} end of group CMSIS_SIMD_intrinsics */


#ifdef __cplusplus
}
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
