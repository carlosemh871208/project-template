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
** Oversampling mode
*/
#define OVERSAMPMSK        0x8000
#define OVERSAMPRSH        15u

#define OVERSAMP16         0u
#define OVERSAMP8          1u

#define CLEANBRRREG        0xFFFFu
#define MANTLSHIFT         4u
#define FRACLSHIFT         0u

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

/*
** RCC defines
*/
#define NOTDEFINED 0x00u

#define HSICLKFREQ 16000000u /* Check values provided by Microcontroller user manual */
#define HSECLKFREQ 20000000u /* Check value from external oscillator */
#define MAXMCUFREQ 84000000u /* Check values provided by Microcontroller user manual */
#define PLL48CLOCK 48000000u /* Check values provided by Microcontroller user manual */

/*System clock sources*/
#define HSISYSCLK  0b00u
#define HSESYSCLK  0b01u
#define PLLSYSCLK  0b10u
#define SRCNOTAPP  0b11u

#define SYSCLKMSK  0xCu
#define SYSCLKSHR  2u
#define SYSCLKERR  0xFFFFFFFFu

#define PLLNMASK   0x7FC0u
#define PLLNRSHFT  6u
#define PLLPMASK   0x30000u
#define PLLPRSHFT  16u
#define PLLMMASK   0x3Fu
#define PLLMRSHFT  0u
#define PLLQMASK   0xF000000u
#define PLLQRSHFT  24u

#define PLLDIV2    0b00u
#define PLLDIV4    0b01u
#define PLLDIV6    0b10u
#define PLLDIV8    0b11u

#define PLLDIVVAL2 2u
#define PLLDIVVAL4 4u
#define PLLDIVVAL6 6u
#define PLLDIVVAL8 8u

#define PLLNWNGCFG 0xFFFFu
#define PLLNFILTER 0x1FFu

#define PLLMWNGCFG 0xFFu
#define PLLMFILTER 0x3Fu

#define PLLQWNGCFG 0xFFu
#define PLLQFILTER 0xFu

/* PLL clock sources*/
#define HSISRCPLL  0u
#define HSESRCPLL  1u

#define PLLSRCMSK  0x400000  
#define PLLSRCSHR  22u

#define ZERODIV    0u

#define FVCOCLKWRG  0xFFFFFFFFu

#define FREQCLKMSK  0x1FFFFFFFu
#define FQ48CLKMSK  0x3FFFFFFu

/*AHB prescaler*/
#define AHBMASK     0xF0u
#define AHBRSHFT    4u

#define SYSCLKNDIV    1u
#define SYSCLKDIV2    2u
#define SYSCLKDIV4    4u
#define SYSCLKDIV8    8u
#define SYSCLKDIV16   16u
#define SYSCLKDIV64   64u
#define SYSCLKDIV128  128u
#define SYSCLKDIV256  256u
#define SYSCLKDIV512  512u

/* APB1 prescaler */
#define APB1MASK      0x1C00u
#define APB1RSHFT     10u

/* APB2 prescaler */
#define APB2MASK      0xE000u
#define APB2RSHFT     13u

#define AHBNOTDIV     1u
#define AHBDIVBY2     2u
#define AHBDIVBY4     4u
#define AHBDIVBY8     8u
#define AHBDIVBY16    16u

/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                              Exported functions prototypes                                        */
/*********************************************************************************************************************/
/*
 ** Peripheral Clock setup
 */
extern uint8  RCC_GetSystemClockSource(void);                     /* Get System Clock source */
extern uint8  RCC_GetPLLClockSource(void);                        /* Get clock source using by PLL*/
extern uint32 RCC_GetSystemClockFrequency(void);                  /* Get System Clock Frequency */
extern uint8  RCC_GetPLLPDivisorFactor(void);                     /* Get the PLLP divisor factor */
extern uint16 RCC_GetPLLNMultiplicatorFactor(void);               /* Get the PLLN multiplicator factor*/
extern uint8  RCC_GetPLLMDivisionFactor(void);                    /* Get the PLLM division factor */
extern uint8  RCC_GetPLLQDivisorFactor(void);                     /* Get the PLLQ divisor factor */
extern uint32 RCC_GetFrequencyVCOClock(uint32 PLLClkInput);       /* Get the Frequency VCO */
extern uint32 RCC_GetPLL48ClockFrequency(void);                   /* Get Clock frequency for USB OTG, SDO*/
extern uint16 RCC_GetAHBClockDivisionFactor(void);                /* Get ABH prescaler Division factor */
extern uint8  RCC_GetAPB1ClockDivisionFactor(void);               /* Get APB1 prescaler Division factor */
extern uint8  RCC_GetAPB2ClockDivisionFactor(void);               /* Get APB2 prescaler Division factor */

/*
 ** Init and De-init
 */
extern void USART_Init(const USART_Config* pUSARTHandle);
extern void USART_DeInit(const USART_Config* pUSARTHandle);

/*
** Set Baud rate
*/
extern uint8 USART_GetOversamplingMode(const USART_Config* pUSARTHandle);
extern void  USART_SetBaudRate(const USART_Config* pUSARTHandle);
/*
 * Data Send and Receive
 */

/*
 ** IRQ Configuration and ISR handling
 */


/*
 ** Other Peripheral Control APIs
 */


/*
 ** Application callback
 */

/*
** Send-receive 
*/

extern void  USART_SendChar(char c);
extern uint8 USART_GetChar(void);

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |             | 21-Sep-2022 | First version of usart.h                                                    |
 *| CMARTI  |    SAM-7    | 22-Sep-2022 | USART driver implementation                                                 |
**********************************************************************************************************************/