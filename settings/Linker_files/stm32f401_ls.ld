ENTRY (Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        *(.isr_vector)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        __text_end__ = .; /* Store the updated location counter value into a symbol '__text_end__'*/
    }> FLASH
    
    .data :
    {
        . = ALIGN(4);
        __data_start__ = .; /* Assign a value to a symbol '__data_start__'*/
        *(.data)
        . = ALIGN(4);
        __data_end__ = .;
    }> SRAM AT> FLASH
    
    .bss :
    {
        . = ALIGN(4);
        __bss_start__ = .; /* Assign a value to a symbol '__bss_start__'*/
        *(.bss)
        . = ALIGN(4);
        __bss_end__ = .;
    }> SRAM
}
