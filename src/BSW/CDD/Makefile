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

#MCAL paths
USARTDIR =  ./USARTDriver
RCCDIR   =  ./RCCDriver

# Compilation flags
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -Werror -o0 -I$(INCDIR)

USARTSRC = $(USARTDIR)/usart.c 
RCCSRC   = $(RCCDIR)/rcc.c

USARTOBJ = $(OBJDIR)/usart.o 
RCCOBJ   = $(OBJDIR)/rcc.o

ser :
	@echo "Executing CDD Makefile"
	@echo Entering USARTDriver.
	@echo Compiling USARTDriver folder source code.
	$(CC) $(CFLAGS) -I$(RCCDIR) $(USARTSRC) -o $(USARTOBJ)
	@echo Leaving USARTDriver folder
	@echo
	@echo Entering RCCDriver.
	@echo Compiling RCCDriver folder source code.
	$(CC) $(CFLAGS) $(RCCSRC) -o $(RCCOBJ)
	@echo Leaving RCCDriver folder
	@echo 

# To add dependencies files
-include $(OBJDIR)/*.d
################################################################################
 #|    ID   | JIRA Ticket |     Date    |            Description               |
 #| carlosm |     NA      | 21-Sep-2022 | First version of Makefile            |
 #| carlosm |     NA      | 23-Sep-2022 | Adedd RCC drivers                    | 
################################################################################
