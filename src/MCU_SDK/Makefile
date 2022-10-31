################################################################################
# $Source: Makefile$
# $Revision: Version 1.0 $
# $Author: Carlos Martinez $
# $Date: 2022-02-23 $
################################################################################
# DESCRIPTION :                                                                                                     
# Makefile
#    Compilation BSW Services
################################################################################
#Microcontroller architecture
MACH = cortex-m4

# Use following variables for ARM cortex m4 microcontrollers.
# Compiler ARMv7
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

#Object path
OBJDIR   = ../../build/obj

#includes path
INCDIR   = ../../inc

#Current path
MCUSDKPATH = ./

#MCU SDKcode files path
MCUSDK = ./mcu_sdk.c

#MCU SDK output files
MCUOBJ = $(OBJDIR)/mcu_sdk.o

#Peripheral paths
ADCPATH    = $(MCUSDKPATH)/ADC
DBGPATH    = $(MCUSDKPATH)/DBG
DMAPATH    = $(MCUSDKPATH)/DMA
GPIOPATH   = $(MCUSDKPATH)/GPIO
GPTIM1PATH = $(MCUSDKPATH)/GPTIM1
GPTIM2PATH = $(MCUSDKPATH)/GPTIM2
I2CPATH    = $(MCUSDKPATH)/I2C
INTPATH    = $(MCUSDKPATH)/INT
IWDGPATH   = $(MCUSDKPATH)/IWDG
OTG_FSPATH = $(MCUSDKPATH)/OTG_FS
PWRPATH    = $(MCUSDKPATH)/PWR
RCCPATH    = $(MCUSDKPATH)/RCC
RTCPATH    = $(MCUSDKPATH)/RTC
SDIOPATH   = $(MCUSDKPATH)/SDIO
SPIPATH    = $(MCUSDKPATH)/SPI
SYSCFGPATH = $(MCUSDKPATH)/SYSCFG
TIM1PATH   = $(MCUSDKPATH)/TIM1
USARTPATH  = $(MCUSDKPATH)/USART
WWDGPATH   = $(MCUSDKPATH)/WWDG

# Compilation flags
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -Werror -o0 -I$(INCDIR)

ucsdk :
	@echo
	@echo "Executing MCU_SDK Makefile"
	@echo
	@$(MAKE) -C $(ADCPATH)
	@echo
	@$(MAKE) -C $(DBGPATH)
	@echo
	@$(MAKE) -C $(DMAPATH)
	@echo
	@$(MAKE) -C $(GPIOPATH)
	@echo
	@$(MAKE) -C $(GPTIM1PATH)
	@echo
	@$(MAKE) -C $(GPTIM2PATH)
	@echo
	@$(MAKE) -C $(I2CPATH)
	@echo
	@$(MAKE) -C $(INTPATH)
	@echo
	@$(MAKE) -C $(IWDGPATH)
	@echo
	@$(MAKE) -C $(OTG_FSPATH)
	@echo
	@$(MAKE) -C $(PWRPATH)
	@echo
	@$(MAKE) -C $(RCCPATH)
	@echo
	@$(MAKE) -C $(RTCPATH)
	@echo
	@$(MAKE) -C $(SDIOPATH)
	@echo
	@$(MAKE) -C $(SPIPATH)
	@echo
	@$(MAKE) -C $(SYSCFGPATH)
	@echo
	@$(MAKE) -C $(TIM1PATH)
	@echo
	@$(MAKE) -C $(USARTPATH)
	@echo
	@$(MAKE) -C $(WWDGPATH)
	@echo
	@echo Microntroller SDK package compiled
	@echo

# To add dependencies files
-include $(OBJDIR)/*.d
################################################################################
 #|    ID   | JIRA Ticket |     Date    |            Description               |
 #| carlosm |     NA      | 15-Oct-2022 | First version of Makefile            |
################################################################################
