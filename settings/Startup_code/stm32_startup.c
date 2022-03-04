/*********************************************************************************************************************/
/*                                                  CODE GROUP                                                       */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: main.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2022-03-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \stm32_startup.c
    File for start running application on microcontroller
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
/*                                                Functions prototypes                                               */
/*********************************************************************************************************************/
/*ARM Cortex M4 exceptions*/
void Reset_Handler               (void);
void NMI_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler           (void)         __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler           (void)         __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler            (void)         __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler          (void)         __attribute__((weak, alias("Default_Handler")));
void SVC_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void DebugMonitor_Handler        (void)         __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void Systick_Handler             (void)         __attribute__((weak, alias("Default_Handler")));

/*STM32F401 interruptions*/
void WWDG_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI16_PVD_Handler           (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI21_TAMPSTAMP_Handler     (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI22_RTCWKUP_Handler       (void)         __attribute__((weak, alias("Default_Handler")));
void FLASH_Handler                (void)         __attribute__((weak, alias("Default_Handler")));
void RCC_Handler                  (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI0_Handler                (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI1_Handler                (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI2_Handler                (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI3_Handler                (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI4_Handler                (void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void ADC_Handler                  (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_Handler        (void)         __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_Handler        (void)         __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_Handler   (void)         __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void TIM2_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void TIM3_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void TIM4_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void SPI1_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void SPI2_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void USART1_Handler               (void)         __attribute__((weak, alias("Default_Handler")));
void USART2_Handler               (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_Handler            (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI17_RTC_Alarm_Handler     (void)         __attribute__((weak, alias("Default_Handler")));
void EXTI18_OTG_FS_WKUP_Handler   (void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void SDIO_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void TIM5_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void SPI3_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void OTG_FS_Handler               (void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_Handler         (void)         __attribute__((weak, alias("Default_Handler")));
void USART6_Handler               (void)         __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_Handler              (void)         __attribute__((weak, alias("Default_Handler")));
void FPU_Handler                  (void)         __attribute__((weak, alias("Default_Handler")));
void SPI4_Handler                 (void)         __attribute__((weak, alias("Default_Handler")));

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/*
* Following constants are extracted from microcontroller user manual
*/
#define SRAM_START  (uint32) 0x20000000u
#define SRAM_END    (uint32) 0x20017FFFu (SRAM SIZE 96 Kbytes)
#define STACK_START (uint32) 0x20018000u

uint32 vector_table[] __attribute__((section(".isr_vector"))) =
{
    STACK_START,                    /*Memory location when stack starts*/
    (uint32) &Reset_Handler,        /*ARM Cortex M4 exception*/
    (uint32) &NMI_Handler,          /*ARM Cortex M4 exception*/
    (uint32) &HardFault_Handler,    /*ARM Cortex M4 exception*/
    (uint32) &MemManage_Handler,    /*ARM Cortex M4 exception*/
    (uint32) &BusFault_Handler,     /*ARM Cortex M4 exception*/
    (uint32) &UsageFault_Handler,   /*ARM Cortex M4 exception*/
    (uint32) 0u,                    /*ARM Cortex M4 reserved*/
    (uint32) 0u,                    /*ARM Cortex M4 reserved*/
    (uint32) 0u,                    /*ARM Cortex M4 reserved*/
    (uint32) 0u,                    /*ARM Cortex M4 reserved*/
    (uint32) &SVC_Handler,          /*ARM Cortex M4 exception*/
    (uint32) &DebugMonitor_Handler, /*ARM Cortex M4 exception*/
    (uint32) 0u,                    /*ARM Cortex M4 reserved*/
    (uint32) &PendSV_Handler,       /*ARM Cortex M4 exception*/
    (uint32) &Systick_Handler,      /*ARM Cortex M4 exception*/ 
    (uint32) &WWDG_Handler,               /*STM32F401 interruption*/
    (uint32) &EXTI16_PVD_Handler,         /*STM32F401 interruption*/
    (uint32) &EXTI21_TAMPSTAMP_Handler,   /*STM32F401 interruption*/
    (uint32) &EXTI22_RTCWKUP_Handler,     /*STM32F401 interruption*/
    (uint32) &FLASH_Handler,              /*STM32F401 interruption*/
    (uint32) &RCC_Handler,                /*STM32F401 interruption*/
    (uint32) &EXTI0_Handler,              /*STM32F401 interruption*/
    (uint32) &EXTI1_Handler,              /*STM32F401 interruption*/
    (uint32) &EXTI2_Handler,              /*STM32F401 interruption*/
    (uint32) &EXTI3_Handler,              /*STM32F401 interruption*/
    (uint32) &EXTI4_Handler,              /*STM32F401 interruption*/
    (uint32) &DMA1_Stream0_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA1_Stream1_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA1_Stream2_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA1_Stream3_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA1_Stream4_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA1_Stream5_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA1_Stream6_Handler,       /*STM32F401 interruption*/
    (uint32) &ADC_Handler,                /*STM32F401 interruption*/
    (uint32) &EXTI9_5_Handler,            /*STM32F401 interruption*/
    (uint32) &TIM1_BRK_TIM9_Handler,      /*STM32F401 interruption*/
    (uint32) &TIM1_UP_TIM10_Handler,      /*STM32F401 interruption*/
    (uint32) &TIM1_TRG_COM_TIM11_Handler, /*STM32F401 interruption*/
    (uint32) &TIM1_CC_Handler,            /*STM32F401 interruption*/
    (uint32) &TIM2_Handler,               /*STM32F401 interruption*/
    (uint32) &TIM3_Handler,               /*STM32F401 interruption*/
    (uint32) &TIM4_Handler,               /*STM32F401 interruption*/
    (uint32) &I2C1_EV_Handler,            /*STM32F401 interruption*/
    (uint32) &I2C1_ER_Handler,            /*STM32F401 interruption*/
    (uint32) &I2C2_EV_Handler,            /*STM32F401 interruption*/
    (uint32) &I2C2_ER_Handler,            /*STM32F401 interruption*/
    (uint32) &SPI1_Handler,               /*STM32F401 interruption*/
    (uint32) &SPI2_Handler,               /*STM32F401 interruption*/
    (uint32) &USART1_Handler,             /*STM32F401 interruption*/
    (uint32) &USART2_Handler,             /*STM32F401 interruption*/
    (uint32) &EXTI15_10_Handler,          /*STM32F401 interruption*/
    (uint32) &EXTI17_RTC_Alarm_Handler,   /*STM32F401 interruption*/
    (uint32) &EXTI18_OTG_FS_WKUP_Handler, /*STM32F401 interruption*/
    (uint32) &DMA1_Stream7_Handler,       /*STM32F401 interruption*/
    (uint32) &SDIO_Handler,               /*STM32F401 interruption*/
    (uint32) &TIM5_Handler,               /*STM32F401 interruption*/
    (uint32) &SPI3_Handler,               /*STM32F401 interruption*/
    (uint32) &DMA2_Stream0_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA2_Stream1_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA2_Stream2_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA2_Stream3_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA2_Stream4_Handler,       /*STM32F401 interruption*/
    (uint32) &OTG_FS_Handler,             /*STM32F401 interruption*/
    (uint32) &DMA2_Stream5_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA2_Stream6_Handler,       /*STM32F401 interruption*/
    (uint32) &DMA2_Stream7_Handler,       /*STM32F401 interruption*/
    (uint32) &USART6_Handler,             /*STM32F401 interruption*/
    (uint32) &I2C3_EV_Handler,            /*STM32F401 interruption*/
    (uint32) &I2C3_ER_Handler,            /*STM32F401 interruption*/
    (uint32) &FPU_Handler,                /*STM32F401 interruption*/
    (uint32) &SPI4_Handler                /*STM32F401 interruption*/
};

/*                                                    Exported Variables                                             */
/*********************************************************************************************************************/

/*                                                 Function Implementation                                           */
/*********************************************************************************************************************/
/* Reset handler, here we call main.c function or bootloader*/
void Reset_Handler (void)
{
   /* Copy .data  section to SRAM*/
   
   /* Initialize the .bss sectino to zero in SRAM*/
   
   /* Call main function*/ 
}

/* Default handler for all exceptions*/
void Default_Handler (void)
{
    for (;;){}
}
/***************************************************Log Projects*******************************************************
 *|    ID   | JIRA Ticket |     Date    |                                Description                                  |
 *| CMARTI  |     NA      | 03-Mar-2022 | First version of stm32_startup.h                                            |
**********************************************************************************************************************/
