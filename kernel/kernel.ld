INPUT(
    kernel.o
    idt.o
    interrupts_common.o
    interrupts_trampoline.o
    interrupt_handler.o
    exceptions.o
    string.o
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
