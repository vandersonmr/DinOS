section .text

extern interrupt_handler

global interrupts_common

interrupts_common:

    pusha

    mov ax, ds
    push eax

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call interrupt_handler

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax


    popa
    sti
    add esp, 8
    iret
