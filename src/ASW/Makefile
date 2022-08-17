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
SERDIR   = ../BSW/Services

#Services include paths
DELDIR   = ../BSW/Services/Delay

#Services path
ASWDIR =  ./Delay

# Compilation flags
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -Werror -o0 -I$(INCDIR) -I$(RTEDIR) -I$(SERDIR) -I$(DELDIR)

SRC = $(ASWDIR)/application_delay.c \

OBJ = $(OBJDIR)/application_delay.o \

asw :
	@echo "Executing Services Makefile"
	@echo Compiling Delay folder source code.
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)
	@echo 

# To add dependencies files
-include $(OBJDIR)/*.d

################################################################################
 #|    ID   | JIRA Ticket |     Date    |            Description               |
 #| carlosm |     NA      | 23-Feb-2022 | First version of Makefile            |
################################################################################
