/*********************************************************************************************************************/
/*                                                 MAIN SOURCE CODE                                                  */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: main.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-03-17 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \main.c
    Here all initialization is made. 
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
#include "std_types.h"
#include "stm32F401re.h"
#include "application_delay.h"
#include "Port.h"
#include "SerialCommGirbauProtocol.h"
#include "usart.h"

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
#define LED_GPIO        GPIOA
#define LED_PIN         5

USART_Config GirbauSerProt = {USART6,
                              USART_STD_BAUD_38400,
                              USART_MODE_TXRX,
                              USART_STOPBITS_2,
                              USART_WORDLEN_8BITS,
                              USART_PARITY_DISABLE,
                              USART_PARITY_EN_EVEN,
                              USART_HW_FLOW_CTRL_NONE
};

uint8 GirbauMsg[50] = {STX,0x00u,1,READSTATUS,0x00u};

/*                                           Main function implementation                                            */
/*********************************************************************************************************************/
int main (void)
{
    //RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOAEN; /*Enable clock to GPIOA*/
    //LED_GPIO->MODER |= (0b01 << (LED_PIN << 1)); /*Set LED pin as output*/ 
    Port_ConfigType output = {PA5,PORTA,PORT_PIN_OUT};
    Init_SerialCommGirbauProtocol (&GirbauSerProt);
    Port_Init(&output);
    for(;;)
    {
        SendCommand(&GirbauSerProt,GirbauMsg);
        LED_GPIO->BSRR = (1 << LED_PIN); /*Set LED pin ON*/
        set_delay_mS(4000);
        LED_GPIO->BSRR = (1 << (LED_PIN + 16)); /*Set LED pin OFF*/
        set_delay_mS(4000);
    }
    return EXIT_PROGRAM;
}
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |     NA      | 17-Mar-2022 | main.c standard version.                                                    |
 *| CMARTI  |     NA      | 21-Mar-2022 | main.c Hello world program: blinking LED                                    |
**********************************************************************************************************************/
