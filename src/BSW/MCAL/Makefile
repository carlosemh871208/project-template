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
IODDIR =  ./IODrivers
DIODIR =  $(IODDIR)/DIODrivers
PORDIR =  $(IODDIR)/PORTDrivers

# Compilation flags
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -Werror -o0 -I$(INCDIR)

SRC = $(PORDIR)/Port.c \

OBJ = $(OBJDIR)/Port.o \

ser :
	@echo "Executing MCAL Makefile"
	@echo Entering IODrivers.
	@echo Compiling PORTDrivers folder source code.
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)
	@echo 

# To add dependencies files
-include $(OBJDIR)/*.d
################################################################################
 #|    ID   | JIRA Ticket |     Date    |            Description               |
 #| carlosm |     NA      | 23-Feb-2022 | First version of Makefile            |
 #| carlosm |     NA      | 23-Aug-2022 | PORTDriver project integration       |
################################################################################
