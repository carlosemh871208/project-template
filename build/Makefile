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

# Makefile variables
RM := rm -rf
# CC = gcc

# Use following variables for ARM cortex m4 microcontrollers.
# Compiler ARMv7
CC = arm-none-eabi-gcc

# ARM CORTEX M4 processor
MACH = cortex-m4

# Output folders .o & binary
OBJDIR = obj
BINDIR = bin

# Includes Directory
INCDIR  = ../inc

# Source Directories
SRCDIR  = ../src
ASWDIR  = ../src/ASW
BSWDIR  = ../src/BSW

# Precompiled libraries Directory
LIBDIR = ../lib

# Settings library Directory
SETDIR = ../settings

# Target place 
TARGET = $(BINDIR)/$(NAME)

# Objects place
OBJS   = $(OBJDIR)/main.o\
         $(OBJDIR)/stm32_startup.o
         

# Compilation flags
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -Werror -o0 -I$(INCDIR)

# Linker flags
LFLAGS = -MD -Wall -Werror -L$(LIBDIR)

.PHONY : all
# Rule to create target
all: $(TARGET)

$(TARGET) : $(OBJS)
	@echo Linker started
	@mkdir -p $(BINDIR) # Create bin directory
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
	@echo $(NAME) Succesfully Builded.

# Compilation stage
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo Starting $(NAME) compilation. 
	@echo Entering $(SRCDIR) folder
	@mkdir -p $(OBJDIR) # Create obj directory
	@echo
	@echo Starting BSW compilation
	@$(MAKE) -C $(BSWDIR)
	@echo
	@echo Starting ASW compilation
	@$(MAKE) -C $(ASWDIR)
	@echo
	@echo Compiling main.c file
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
	
################################################################################
 #|    ID   | JIRA Ticket |     Date    |            Description               |
 #| carlosm |     NA      | 23-Feb-2022 | First version of Makefile            |
 #| carlosm |     NA      | 03-Mar-2022 | Makefile version for STM32F401       |
################################################################################
