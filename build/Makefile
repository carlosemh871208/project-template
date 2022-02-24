################################################################################
# $Source: Makefile$
# $Revision: Version 1.0 $
# $Author: Carlos Martinez $
# $Date: 2022-02-23 $
################################################################################
# DESCRIPTION :                                                                                                     
# Makefile
#    Compilation script for entire project
################################################################################
# Project name (Shall be changed)
NAME = projectName

# Makefile variables
RM := rm -rf
CC = gcc

# Use following variables for ARM cortex m4 microcontrollers.
# Compiler ARMv7
# CC = arm-none-eabi-gcc

# ARM CORTEX M4 processor
# MACH = cortex-m4

# Output folders .o & binary
OBJDIR = obj
BINDIR = bin

# Includes Directory
INCDIR  = ../inc

# Source Directory
SRCDIR  = ../src

# Precompiled libraries Directory
LIBDIR = ../lib

# Settings library Directory
SETDIR = ../settings

# Target place 
TARGET = $(BINDIR)/$(NAME)

# Objects place
OBJS   = $(OBJDIR)/main.o 

# Compilation flags
CFLAGS = -MD -Wall -r -I$(INCDIR)

# Linker flags
LFLAGS = -MD -Wall -L$(LIBDIR)

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
	@echo Entering $(SRCDIR) folder
	@mkdir -p $(OBJDIR) # Create obj directory
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
################################################################################
