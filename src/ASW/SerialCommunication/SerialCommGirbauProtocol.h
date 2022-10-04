/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: SerialCommGirbauProtocol.h $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-09-22 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \SerialCommGirbauProtocol.h
    Here we define all data types required by the project.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef SERIALCOMMGIRBAUPROTOCOL_H_
#define SERIALCOMMGIRBAUPROTOCOL_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "std_types.h" /*Can be changed this according AUTOSAR*/
#include "stm32F401re.h" /* Depends on CleanReader microcontroller */

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
#define INITVALUE    0x00u /* Initialization variable value */
#define FRAMEINDEX   1u

/* CRC definitions */
#define DATABYTESIDX 1u /* Index to get number of data bytes from frame */
#define HEADERBYTES  5u /* Number of header bytes*/

/* Command IDs */
#define READSTATUS      0x0Au
#define READPHASE       0x76u
#define EDITPHASE       0x77u
#define PROGRAMSTART    0xA7u
#define PROGRAMSELECT   0xA6u
#define RDEXTRAOPTIONS  0x7Au
#define EDEXTRAOPTIONS  0x7Bu
#define READPRICES      0x78u
#define EDITPRICES      0x79u
#define READDISPLAY     0x72u
#define WRITEDISPLAY    0x70u
#define FREEZEKBOARD    0x71u
#define READINFO1       0xA4u

/* Washer status */
#define WASHERALARM     0x00u
#define STANDBY         0x01u
#define DOOROPENED      0x02u
#define DOORCLOSED      0x03u
#define READYTOSTART    0x04u
#define WASHINGCYCLE    0x05u
#define DOOROPONCYCLE   0x06u

/* Alarm status */
#define REMWASHTMIDX    5u
#define REMWASHVAl      0x00u
#define EXEPROGIDX      6u
#define EXEPROGVAL      0x00u
#define DOORSTSIDX      10u
#define DOORSTSCLO      0x00  
#define DOORSTSOPN      0x01  
#define ALARMIDX        7u    
#define NOALARM         0x00u
#define ALM_door        0x03u
#define ALM_SL          0x04u
#define ALM_L           0x05u
#define ALM_C2          0x06u 
#define ALM_E           0x07u
#define ALM_A           0x08u
#define ALM_C           0x09u
#define ALM_Prob        0x0Au
#define ALM_BAL         0x0Bu
#define ALM_VAR_0       0x14u
#define ALM_VAR_1       0x15u 
#define ALM_VAR_2       0x16u
#define ALM_VAR_3       0x17u
#define ALM_VAR_4       0x18u
#define ALM_VAR_5       0x19u
#define ALM_VAR_6       0x1Au
#define ALM_VAR_7       0x1Bu
#define ALM_VAR_8       0x1Cu

/* Machines models */
#define HS_6008         0x03u
#define EH020           0x03u 
#define MS_610          0x04u 
#define RMS610          0x04u
#define RMS610          0x04u
#define EM025           0x04u
#define REM025          0x04u
#define HS_6017         0x05u
#define EH040           0x05u
#define HS_6013         0x06u
#define EH030           0x06u
#define MS_623          0x07u
#define RMS623          0x07u
#define EM055           0x07u
#define REM055          0x07u
#define MS_613          0x08u
#define RMS613          0x08u
#define EM030           0x08u
#define REM033          0x08u
#define MS_617          0x09u
#define RMS617          0x09u
#define EM040           0x09u
#define REM040          0x09u
#define HS_6023         0x0Au
#define EH055           0x0Au
#define EH090           0x0Bu
#define MG_613          0x0Cu
#define RMG613          0x0Cu
#define MG030           0x0Cu
#define RMG033          0x0Cu
#define MG_617          0x0Du
#define RMG617          0x0Du
#define MG040           0x0Du
#define RMG040          0x0Du
#define MG_623          0x0Eu
#define RMG623          0x0Eu
#define MG055           0x0Eu
#define RMG055          0x0Eu
#define RMG628          0x0Fu
#define RMG070          0x0Fu
#define RMS628          0x10u
#define REM070          0x10u
#define HS_6024         0x11u
#define EH060           0x11u

/* Status definitions */
#define FAIL            0x00u
#define OK              0x01u

/* Selected program */
#define PROGRAM1        1u
#define PROGRAM2        2u
#define PROGRAM3        3u
#define PROGRAM4        4u

/*  */

/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/
extern void     Init_SerialCommGirbauProtocol (USART_Config* USARTPort); /* Initialize Girbau Communication Protocol */
extern void     SendCommand (USART_Config* USARTPort, uint8_t* machineCommand); /* Send frame throught configurated USART port */
extern uint8_t* ReceiveCommand (USART_Config* USARTPort); /* Received command response from washer machine */

#endif /* SERIALCOMMGIRBAUPROTOCOL_H_ */

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |     NA      | 22-Sep-2022 | FFirst version of Continental Girbau serial communication protocol          |
**********************************************************************************************************************/
