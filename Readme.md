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
