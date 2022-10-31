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
OBJDIR   = ../../../build/obj

#includes path
INCDIR   = ../../../inc

#CDD paths

# Compilation flags
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -Werror -o0 -I$(INCDIR)

ser :
	@echo "Executing SYSCFG Makefile"
	@echo 

# To add dependencies files
-include $(OBJDIR)/*.d
################################################################################
 #|    ID   | JIRA Ticket |     Date    |            Description               |
 #| carlosm |     NA      | 21-Sep-2022 | First version of Makefile            |
 #| carlosm |     NA      | 23-Sep-2022 | Adedd RCC drivers                    | 
################################################################################
