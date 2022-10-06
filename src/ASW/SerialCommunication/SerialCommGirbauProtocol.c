/*********************************************************************************************************************/
/*                                                 MAIN SOURCE CODE                                                  */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: SerialCommGirbauProtocol.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-09-22 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \SerialCommGirbauProtocol.c
    Connects CleanReader terminal with Continental Girbau Machine:
    Following features shall be implemented according Girbau requirements:
         a. Physical specification: RS-485, 38400 baud, no parity, 2 stop bits. Protocol not based on RTS/CTS 
            control.
         b. The washing machine is always the slave.
         c. The response time of a reading command is lower than 10 ms.
         d. The normal response time of a writing command is lower than 50 ms. However, it can be of 
             1 second in some cases.
        
        Frame format:
        Byte 0: STX (0x02)
        Byte 1: N: length of data bytes (depending of the command)
        Byte 2: Machine Address. (Must be the machine address. From 1 to 99) String (3): Command Identification
        Byte 3: Command Identification
        Byte 4: Machine Type
        Byte 5 to (5+N-1)): Data bytes
        Byte 5+N: result of the CRC algorithm for the first N bytes

        Byte 2 Machine Address configuration on washer
        See Operating Instructions for HS-6, MS-6, RMS/RMG6, EH, EM, REM COIN CONTROL washing machines Chapter 9.
        In Mod menu, parameter id-?
        Board identification default value is 0. If the board’s net identification is zero (0), communication is disabled. 
        If the board’s identification is other than zero, the machine is ready to answer the commands addressed to it.

        Byte 4: Machine type
        On washers, when the master sends a frame, this must be 0x00. The washer responds depending on the control:
        - Coin control: 0x01

        How to calculate CRC
        CRC calculation for a frame of N bytes of data length. Data is contained in String(x):
        crc = 0
        x=0
        for x = 0 To (5+N-1)
        crc = crc X or String(x) Next x
        If crc == 0x02 then crc = 0x03 String(5+N) = crc
        i.e.
            Command = 0x0A
            If machine identifier = 1
            CRC = 0x02 Xor 0x00 Xor 0x01 Xor 0x0A Xor 0x00 = 0x09
            The frame to be sent will be: 0x02 + 0x00 + 0x01 + 0x0A + 0x00 + 0x09
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
/* Following includes headers shall be changed according CleanReader dependencies */
#include "std_types.h" /*Can be changed this according AUTOSAR*/
#include "stm32F401re.h" /* Depends on CleanReader microcontroller */
#include "usart.h" /*Contains API for USART por configuration*/
#include "SerialCommGirbauProtocol.h" /* Girbau Serial Communication protocol header*/

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
const USART_Config GirbauSerialPort = {USART2,
                                       USART_STD_BAUD_38400,
                                       USART_MODE_TXRX,
                                       USART_STOPBITS_2,
                                       USART_WORDLEN_8BITS,
                                       USART_PARITY_DISABLE,
                                       USART_PARITY_EN_EVEN,
                                       USART_HW_FLOW_CTRL_NONE
                                       };

uint8_t reception_buffer[50];

/*                                  SerialCommGirbauProtocol function definition                                     */
/*********************************************************************************************************************/
extern void     Init_SerialCommGirbauProtocol (USART_Config* USARTPort); /* Initialize Girbau Communication Protocol */
extern void     SendCommand (USART_Config* USARTPort, uint8_t* machineCommand); /* Send frame throught configurated USART port */
extern uint8_t* ReceiveCommand (USART_Config* USARTPort); /* Received command response from washer machine */
//static uint8_t  GetWasherStatus (uint8_t* frame); /* Return washer current status */
static uint8_t  GetFrameCRC (uint8_t* frame); /*Return CRC of the frame */
static void     ConfigureCommandFormat (uint8_t* frame); /* Configure command format according Girbau specification */

/*                                  SerialCommGirbauProtocol function implementation                                 */
/*********************************************************************************************************************/
/*
** Initialize Girbau Communication Protocol
*/
extern void Init_SerialCommGirbauProtocol (USART_Config* USARTPort)
{
    USART_Init(USARTPort);
}

/*
** Send frame throught configurated USART port 
*/
extern void SendCommand (USART_Config* USARTPort, uint8_t* machineCommand)
{
    uint8_t frLenght = machineCommand[DATABYTESIDX]+HEADERBYTES;
    uint8_t index = 0;
    ConfigureCommandFormat(machineCommand);
    for(index = 0; index <= frLenght; index++)
    {
        USART_SendChar(machineCommand[index]);
    }
}


/*
** Received command response from washer machine
*/
extern uint8_t* ReceiveCommand (USART_Config* USARTPort)
{
    uint8_t buffIdx = 0u;
    uint8_t buffLen = 0u;
    for(buffIdx = 0; buffIdx <= (HEADERBYTES + buffLen); buffIdx++)
    {
        reception_buffer[buffIdx] = USART_GetChar();
        if(DATABYTESIDX == buffIdx)
        {
            buffLen = reception_buffer[buffIdx];
        }else{
            /* Do nothing */
        }
    }
    return reception_buffer;
}

/*
** Return washer current status
*/

/*
static uint8_t GetWasherStatus (uint8_t* frame)
{
    uint8_t wStatus = FAIL;
    if(NOALARM != frame[ALARMIDX])
    {
        wStatus = WASHERALARM;
    }else if((NOALARM == frame[ALARMIDX]) && (REMWASHVAl == frame[REMWASHTMIDX]) && (EXEPROGVAL == frame[EXEPROGIDX]) &&
              DOORSTSOPN == frame[DOORSTSIDX])
    {
        wStatus = DOOROPENED;
    }else if((NOALARM == frame[ALARMIDX]) && (REMWASHVAl == frame[REMWASHTMIDX]) && (EXEPROGVAL == frame[EXEPROGIDX]) &&
              DOORSTSCLO == frame[DOORSTSIDX])
    {
        wStatus = DOORCLOSED;
    }else if((NOALARM == frame[ALARMIDX]) && (REMWASHVAl != frame[REMWASHTMIDX]) && (EXEPROGVAL != frame[EXEPROGIDX]) &&
              DOORSTSCLO == frame[DOORSTSIDX])
    {
        wStatus = WASHINGCYCLE;
    }else if((NOALARM == frame[ALARMIDX]) && (REMWASHVAl == frame[REMWASHTMIDX]) && (EXEPROGVAL != frame[EXEPROGIDX]) &&
              DOORSTSOPN == frame[DOORSTSIDX])
    {
        wStatus = DOOROPONCYCLE;
    }
    return wStatus;
}

*/

/*
** Return CRC of the frame
*/
static uint8_t GetFrameCRC(uint8_t* frame)
{
    uint8_t crc = INITVALUE;
    uint8_t frameCounter;
    for(frameCounter = 0u; frameCounter < (HEADERBYTES + frame[DATABYTESIDX]);frameCounter++)
    {
        crc ^= frame[frameCounter];
    }
    return crc;
}

/*
** Configure command format according Girbau specification
*/
static void ConfigureCommandFormat (uint8_t* frame)
{
    uint8_t* auxFrame = frame;
    uint8_t  frameBytes = (auxFrame[DATABYTESIDX]);
    auxFrame[frameBytes+HEADERBYTES] = GetFrameCRC(frame);
}

/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |     NA      | 22-Sep-2022 | SerialCommGirbauProtocol.c first version                                    |
**********************************************************************************************************************/
