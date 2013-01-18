section .text

extern exception_zero
extern exception_breakpoint
extern exception_overflow

global int0
global int3
global int4

int0:
    cli
    pusha
    push gs
    push fs
    push ds
    push es
    call exception_zero
    pop es
    pop ds
    pop fs
    pop gs
    popa
    sti
    iret

int3:
    cli
    pusha
    push gs
    push fs
    push ds
    push es
    call exception_breakpoint
    pop es
    pop ds
    pop fs
    pop gs
    popa
    sti
    iret

int4:
    cli
    pusha
    push gs
    push fs
    push ds
    push es
    call exception_overflow
    pop es
    pop ds
    pop fs
    pop gs
    popa
    sti
    iret
