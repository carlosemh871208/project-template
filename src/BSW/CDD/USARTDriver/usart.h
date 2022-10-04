/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: usart.h $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-09-21 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \usart.h
    Here we define types and function used by usart driver.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef USART_H_
#define USART_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "std_types.h"
#include "stm32F401re.h"
/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/*
 * Configuration structure for USARTx peripheral
 */
typedef struct
{
	USART_TypeDef* USART_Port;
	uint32         USART_Baud;
    uint8          USART_Mode;
	uint8          USART_NoOfStopBits;
	uint8          USART_WordLength;
	uint8          USART_ParityControl;
	uint8          USART_ParitySelection;
	uint8          USART_HWFlowControl;
}USART_Config;

/*
 *@USART_Mode
 *Possible options for USART_Mode
 */
#define USART_MODE_ONLY_RX 0b01
#define USART_MODE_ONLY_TX 0b10
#define USART_MODE_TXRX    0b11

/*CR1 register left shift value*/
#define SHIFTRXTX   2
#define SHIFTPSRG   9
#define SHIFTPCER  10
#define SHIFTMREG  11
#define SHIFTUERG  13
#define SHIFTOVER8 15

/*CR2 register left shift value*/
#define SHIFTSTOP 10

/*CR3 register left shift value*/
#define SHIFTHWFC  8

/*SR register macros*/
#define TXEMASK   0x00000080
#define SHIFTXE            7
#define TCMASK    0x00000040
#define SHIFTC             6
#define RXNEMASK  0x00000020
#define SHIFTRXNE          5 

/*
 *@USART_Baud
 *Possible options for USART_Baud
 */
#define USART_STD_BAUD_1200					1200
#define USART_STD_BAUD_2400					2400
#define USART_STD_BAUD_9600					9600
#define USART_STD_BAUD_19200 				19200
#define USART_STD_BAUD_38400 				38400
#define USART_STD_BAUD_57600 				57600
#define USART_STD_BAUD_115200 				115200
#define USART_STD_BAUD_230400 				230400
#define USART_STD_BAUD_460800 				460800
#define USART_STD_BAUD_921600 				921600
#define USART_STD_BAUD_2M 					2000000
#define SUART_STD_BAUD_3M 					3000000


/*
 *@USART_ParityControl
 *Possible options for USART_ParityControl
 */
#define USART_PARITY_EN_EVEN  0
#define USART_PARITY_EN_ODD   1

#define USART_PARITY_DISABLE  0
#define USART_PARITY_ENABLE   1

/*
 *@USART_WordLength
 *Possible options for USART_WordLength
 */
#define USART_WORDLEN_8BITS              0
#define USART_WORDLEN_9BITS              1
#define NINEBITSMASK         (uint16)0x1FF
#define EIGHTBITSMASK        (uint8)  0xFF
#define SEVENBITSMASK        (uint8)  0x7F

/*
 *@USART_NoOfStopBits
 *Possible options for USART_NoOfStopBits
 */
#define USART_STOPBITS_1     0b00
#define USART_STOPBITS_0_5   0b01
#define USART_STOPBITS_2     0b10
#define USART_STOPBITS_1_5   0b11

/*
 *@USART_HWFlowControl
 *Possible options for USART_HWFlowControl
 */
#define USART_HW_FLOW_CTRL_NONE    	0b00
#define USART_HW_FLOW_CTRL_CTS    	0b01
#define USART_HW_FLOW_CTRL_RTS    	0b10
#define USART_HW_FLOW_CTRL_CTS_RTS	0b11

/*
 *@USART_Port number
 *Possible options for USART port number
 */
#define USARTPORT1 0
#define USARTPORT2 1
#define USARTPORT6 2

/*
** Enable or disable clock for USART
*/
#define USART1PCCDIS 0xFFFFFFEFu
#define USART2PCCDIS 0xFFFDFFFFu
#define USART6PCCDIS 0xFFFFFFDFu

/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/
/*
 ** Peripheral Clock setup
 */
extern void USART_PeriClockControl(const USART_Config* pUSARTHandle, uint8 EnorDi);

/*
 ** Init and De-init
 */
extern void USART_Init(const USART_Config* pUSARTHandle);
extern void USART_DeInit(const USART_Config* pUSARTHandle);

/*
** Set Baud rate
*/
extern void USART_SetBaudRate(const USART_Config* pUSARTHandle);

/*
 * Data Send and Receive
 */
extern void USART_SendData (const USART_Config* pUSARTHandle, uint8* pTxBuffer, uint32 Lenght);
extern void USART_ReceiveData (const USART_Config* pUSARTHandle, uint8* pRxBuffer, uint32 Lenght);

extern uint8 USART_SendDataIT (USART_Config* pUSARTHandle,uint8* pTxBuffer, uint32_t Lenght);
extern uint8 USART_ReceiveDataIT (USART_Config* pUSARTHandle, uint8* pRxBuffer, uint32_t Lenght);

/*
 ** IRQ Configuration and ISR handling
 */
extern void USART_IRQInterruptConfig (uint8 IRQNumber, uint8 EnorDi);
extern void USART_IRQPriorityConfig (uint8 IRQNumber, uint32 IRQPriority);
extern void USART_IRQHandling (USART_Config* pHandle);

/*
 ** Other Peripheral Control APIs
 */
extern void  USART_PeripheralControl (const USART_Config* pUSARTHandle, uint8 EnOrDi);
extern uint8 USART_GetFlagStatus(const USART_Config* pUSARTHandle, uint8 StatusFlagName);
extern void  USART_ClearFlag (USART_TypeDef* pUSARTx, uint16 StatusFlagName);

/*
 ** Application callback
 */
extern void USART_ApplicationEventCallback(USART_Config* pUSARTHandle, uint8_t AppEv);

extern void  USART_SendChar(char c);
extern uint8 USART_GetChar(void);

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |             | 21-Sep-2022 | First version of usart.h                                                    |
 *| CMARTI  |    SAM-7    | 22-Sep-2022 | USART driver implementation                                                 |
**********************************************************************************************************************/