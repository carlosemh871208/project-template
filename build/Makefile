################################################################################
# $Source: Makefile$
# $Revision: Version 1.0 $
# $Author: Carlos Martinez $
# $Date: 2022-03-03 $
################################################################################
# DESCRIPTION :                                                                                                     
# Makefile
#    Compilation script for entire project
################################################################################
# Project name (Shall be changed)
NAME = stm32f401-exe

# Microcontroller name
DEVICE = STM32F401RE

# Makefile variables
RM := rm -rf
# CC = gcc

# Use following variables for ARM cortex m4 microcontrollers.
# Compiler ARMv7
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

# ARM CORTEX M4 processor
MACH = cortex-m4

# Output folders .o & binary
OBJDIR = obj
BINDIR = bin

# Includes Directory
INCDIR  = ../inc

ASWINC  = -I../src/ASW\


MCUINC  = -I../src/MCU_SDK      \
          -I../src/MCU_SDK/RCC  \

# Source Directories
SRCDIR  = ../src
ASWDIR  = ../src/ASW
BSWDIR  = ../src/BSW
MCUSDK  = ../src/MCU_SDK
RTEDIR  = ../src/RTE 

# Precompiled libraries Directory
LIBDIR = ../lib

# Settings library Directory
SETDIR = ../settings
LKRDIR = ../settings/Linker_files

# Target place 
TARGET = $(BINDIR)/$(NAME).elf
TGTBIN = $(BINDIR)/$(NAME).bin
TGTHEX = $(BINDIR)/$(NAME).hex

# Objects place
OBJS   = $(OBJDIR)/main.o\
         $(OBJDIR)/stm32_startup.o\
		 $(OBJDIR)/rcc.o\
         
#JLINK tool
JLINK = /usr/bin/JLinkExe
DEBUG = /usr/bin/JLinkGDBServer

# Compilation flags
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -Werror -o0 -I$(INCDIR) $(ASWINC) $(MCUINC)

# Linker flags
LFLAGS = -nostdlib -Wall -Werror -T $(LKRDIR)/stm32f401_ls.ld -Wl,-Map=$(BINDIR)/$(NAME).map

.PHONY : all
# Rule to create target
all: $(TARGET)

$(TARGET) : $(OBJS)
	@echo Linker started
	@mkdir -p $(BINDIR) # Create bin directory
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
	$(OBJCOPY) -O ihex $(TARGET) $(TGTHEX)
	$(OBJCOPY) -O binary $(TARGET) $(TGTBIN)
	@echo
	$(SIZE) $(TARGET)
	@echo
	@echo $(NAME) Succesfully Builded.

# Compilation stage
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo Starting $(NAME) compilation. 
	@echo Entering $(SRCDIR) folder
	@mkdir -p $(OBJDIR) # Create obj directory
	@echo
	@echo Starting MCU_SDK compilation
	@$(MAKE) -C $(MCUSDK)
	@echo
	@echo Starting BSW compilation
	@$(MAKE) -C $(BSWDIR)
	@echo
	@echo Starting ASW compilation
	@$(MAKE) -C $(ASWDIR)
	@echo
	@echo Compiling main.c file.
	$(CC) $(CFLAGS) $< -o $@
	@echo
	
$(OBJDIR)/%.o : $(SETDIR)/Startup_code/%.c
	@echo Compiling startup code.
	$(CC) $(CFLAGS) $< -o $@
	@echo

# To add dependencies files
-include $(OBJDIR)/*.d

# clean project
.PHONY : clean
clean :
	@echo Cleaning all project.
	@$(RM) $(OBJDIR) $(BINDIR)
	@echo End of cleaning
	
# To program microcontroller
$(BINDIR)/jflash: $(TGTBIN)
	@touch $@
	@echo Device $(DEVICE) > $@
	@echo si 1'\n'Speed 4000 >> $@
	@echo loadbin $< 0x08000000 >> $@
	@echo r'\n'g'\n'qc >> $@

.PHONY : flash
flash: $(BINDIR)/jflash
	@echo JLink execution started
	$(JLINK) -commanderscript $<
	
.PHONY : debug
debug:
	$(DEBUG) -if SWD -device $(DEVICE)
################################################################################
 #|    ID   | JIRA Ticket |     Date    |            Description               |
 #| carlosm |     NA      | 23-Feb-2022 | First version of Makefile            |
 #| carlosm |     NA      | 03-Mar-2022 | Makefile version for STM32F401       |
 #| carlosm |     NA      | 14-Mar-2022 | Added .hex and .bin extensions       |
 #| carlosm |     NA      | 14-Mar-2022 | Added load command to flash uC       |
 #| carlosm |     NA      | 17-Mar-2022 | Added script for flashing firmware   |
 #| carlosm |     NA      | 17-Aug-2022 | Modified due RTE folder change       |
 #| carlosm |    SAM-7    | 15-Oct-2022 | Added MCU SDK folder to project      |
################################################################################
