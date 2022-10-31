################################################################################
# $Source: Makefile$
# $Revision: Version 1.0 $
# $Author: Carlos Martinez $
# $Date: 2022-02-23 $
################################################################################
# DESCRIPTION :                                                                                                     
# Makefile
#    Compilation BSW
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
RTEDIR   = ../RTE

#Services include paths

#Services path
ASWDIR =  ./

# Compilation flags
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -Werror -o0 -I$(INCDIR) -I$(RTEDIR)

asw :
	@echo "Executing ASW Makefile"
	@echo "Entering to SWC x folder" 
	@echo 

# To add dependencies files
-include $(OBJDIR)/*.d

################################################################################
 #|    ID   | JIRA Ticket |     Date    |            Description               |
 #| carlosm |     NA      | 23-Feb-2022 | First version of Makefile            |
################################################################################
