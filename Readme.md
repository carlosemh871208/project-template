This is a general project template.
Into build folder general Makefile will be found.
	Steps to compile:
		1 Go to /projectName/build/
		2 Open terminal here.
		3 On terminal write make.
		4 The project will be builded, objects files can be located at /obj dir and executable can be located at /bin.

Into include folder "inc" external or general libraries must be placed.

Into precompiled libraries folder "lib" must be place precompiled libraries .so or .a files. 

Into settings folder, will be found three folders:
	Linker_files: Where linker script shall be added.
	Startup_code: Where source code for microcontroller shall be added.
	Bootloader:   Here bootloader code shall be added.
  
Into source folder "src", a main.c file is included, there are two more folders.
	ASW(Application software): On this folder all software components shall be added.
				   For every functionality please create a folder with the SWC name and follow intructions
				   on Makefile folder to added the component into project build.
	BSW(Basic software): On this folder low level drivers shall be added. Here we can find more folders (In case of embedded project): 
		RTE(Run Time Environment): This is a virtual bus that connects ASW with BSW.
		Services: Here must be defined services as RTOS, Diagnostics.
		HAL(Hardware Abstraction Layer): This the abstraction of low level drivers provided by the mcal.
		MCAL(Microcontroller Abstraction Layer): This layer provide the drivers for upper layers, this is
							 the abstraction of microncontroller resources converted to code. 
							 
STM32F401_baseline
This Baseline is for STM32F401
Software development.

Important notes:
Use following command to see memory sections:
arm-none-eabi-onjbump -h yourfile.o

In this project we have differente sections:
.text   -> this section contains code or program instructions.
.data   -> this section contains initialized data (initialized global and static variables).
.bss    -> this section contains uninitialized data (uninitialized global and static variables).
.rodata -> this section contains read only data.

Intructions (code) are stored in flash memory of the microcontroller.
Data (variables) are stored in main memory (RAM)

Why data is stored in RAM but not in FLASH?
Because, data are nothing, but variables can change at any time during runtime of the program.

/***************************************************************************************************************************************************************/
Installation packages
This file contains instructions for software development tools.

Install Snap.
1. sudo apt-get update
2. sudo apt list --installed | grep -i snapd
3. sudo apt-get install snapd snapd-xdg-open

Install package for Development
1. sudo apt-get update
2. sudo apt-get install build-essential

Install Make
1. sudo apt-get update
2. sudo apt-get install make

Install git
1. sudo apt-get update
2. sudo apt-get install git-all

Install python
1. sudo apt-get update
2. sudo apt-get install python3

Install tree
1. sudo apt-get install tree

Install OpenCV.
http://techawarey.com/programming/install-opencv-c-c-in-ubuntu-18-04-lts-step-by-step-guide/

Install OpenGL.
http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/

Install Googletest
https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
http://www.electronicsfaq.com/2018/01/googletest-on-ubuntu.html (examples)

Install SEGGER JLink 
https://boundarydevices.com/debugging-using-segger-j-link-jtag/

Install ARM Cortex M4 compiler
https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
cd ~/Downloads
sudo tar xjf gcc-arm-none-eabi-10.3-2021.10-aarch64-linux.tar.bz2 -C /usr/share/
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gdb-add-index /usr/bin/arm-none-eabi-gdb-add-index
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gdb-add-index-py /usr/bin/arm-none-eabi-gdb-add-index-py
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc-nm /usr/bin/arm-none-eabi-gcc-nm
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-addr2line /usr/bin/arm-none-eabi-addr2line
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-strings /usr/bin/arm-none-eabi-strings
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-lto-dump /usr/bin/arm-none-eabi-lto-dump
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gprof /usr/bin/arm-none-eabi-gprof
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gdb-py /usr/bin/arm-none-eabi-gdb-py
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gdb /usr/bin/arm-none-eabi-gdb
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcov-tool /usr/bin/arm-none-eabi-gcov-tool
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcov-dump /usr/bin/arm-none-eabi-gcov-dump
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcov /usr/bin/arm-none-eabi-gcov
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc-ranlib /usr/bin/arm-none-eabi-gcc-ranlib
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc-ar /usr/bin/arm-none-eabi-gcc-ar
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc-10.3.1 /usr/bin/arm-none-eabi-gcc-10.3.1
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc /usr/bin/arm-none-eabi-gcc
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-g++ /usr/bin/arm-none-eabi-g++
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-elfedit /usr/bin/arm-none-eabi-elfedit
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-c++filt /usr/bin/arm-none-eabi-c++filt
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-c++ /usr/bin/arm-none-eabi-c++
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-strip /usr/bin/arm-none-eabi-strip
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-size /usr/bin/arm-none-eabi-size
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-readelf /usr/bin/arm-none-eabi-readelf
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-ranlib /usr/bin/arm-none-eabi-ranlib
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-objdump /usr/bin/arm-none-eabi-objdump
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-objcopy /usr/bin/arm-none-eabi-objcopy
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-nm /usr/bin/arm-none-eabi-nm
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-ld.bfd /usr/bin/arm-none-eabi-ld.bfd
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-ld /usr/bin/arm-none-eabi-ld
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-cpp /usr/bin/arm-none-eabi-cpp
sudo ln -s /usr/share/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-as /usr/bin/arm-none-eabi-as

Install OpenOCD
https://installati.one/ubuntu/20.04/openocd/

Install JAVA
sudo apt-get update
sudo apt install openjdk-17-jre
java --version

Install Eclipse
https://itsfoss.com/install-latest-eclipse-ubuntu/

Github personal access token
https://stackoverflow.com/questions/35942754/how-can-i-save-username-and-password-in-git
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

/*****************************************************************************************************************************/
Working following Autosar standard
A new Baseline has been created (autosar_stm32f401e_baseline).
Branches derived from autosar_stm32f401e_baseline shall follow next instructions:
	(autosar_block)_(autosar_main-_layer)_(autosar_module)_(autosar_submodule).
	i.e. bsw_mcal_iodrivers_diodriver
	asw_(SWC_name)
	asw_highbeams