INPUT(
    kernel.o
    idt.o
    interrupts_trampoline.o
    io.o
    serial.o
    exceptions.o
    string.o
    screen.o
    cpuid.o
    vm/paging.o
    vm/vm.o
    kmalloc.o
    linkedList.o
    mm.o
)

ENTRY(main);

SECTIONS
{
    . = 0x100000;

    .text BLOCK(8K) : ALIGN(8K)
    {
        *(.text)
    }

    .rodata BLOCK(8K) : ALIGN(8K)
    {
        *(.rodata*)
    }

    .data BLOCK(8K) : ALIGN(8K)
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
