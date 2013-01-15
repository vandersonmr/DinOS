INPUT(
    kernel.o
    screen.o
    cpuid.o
    )

ENTRY(main);

SECTIONS
{
    . = 0x100000;

    .text ALIGN (0x100000) :
    {
        *(.text)
    }

    .rodata ALIGN (0x100000) :
    {
        *(.rodata*)
    }

    .data ALIGN (0x100000) :
    {
        *(.data)
    }

    .bss :
    {
        sbss = .;
        *(COMMON)
            *(.bss)
            ebss = .;
    }
}
