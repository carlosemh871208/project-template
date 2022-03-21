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

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
#define LED_GPIO        GPIOA
#define LED_PIN         5

static void delay(unsigned time)
{
    for (unsigned i=0; i<time; i++)
        for (volatile unsigned j=0; j<20000; j++);
}

/*                                           Main function implementation                                            */
/*********************************************************************************************************************/
int main (void)
{
    RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOAEN; /*Enable clock to GPIOA*/
    LED_GPIO->MODER |= (0b01 << (LED_PIN << 1)); /*Set LED pin as output*/   
    for(;;)
    {
        LED_GPIO->BSRR = (1 << LED_PIN); /*Set LED pin ON*/
        delay(200);
        LED_GPIO->BSRR = (1 << (LED_PIN + 16)); /*Set LED pin OFF*/
        delay(200);
    }
    return EXIT_PROGRAM;
}
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |     NA      | 17-Mar-2022 | main.c standard version.                                                    |
 *| CMARTI  |     NA      | 21-Mar-2022 | main.c Hello world program: blinking LED                                    |
**********************************************************************************************************************/
