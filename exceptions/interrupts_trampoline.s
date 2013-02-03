;http://www.osdever.net/tutorials/view/interrupts-exceptions-and-idts-part-2-exceptions

section .text

extern exception_zero
extern exception_breakpoint
extern exception_overflow
extern exception_doublefault
extern exception_syscall
extern exception_generalprotection
extern exception_pagefault

global int0
global int3
global int4
global int8
global int13
global int14
global int128 ; 0x80

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

int8:
    cli
    pusha
    push gs
    push fs
    push ds
    push es
    call exception_doublefault
    pop es
    pop ds
    pop fs
    pop gs
    popa
    sti

int13:
    cli
    pusha
    push gs
    push fs
    push ds
    push es
    call exception_generalprotection
    pop es
    pop ds
    pop fs
    pop gs
    popa
    sti

int14:
    cli
    pusha
    push gs
    push fs
    push ds
    push es
    call exception_pagefault
    pop es
    pop ds
    pop fs
    pop gs
    popa
    sti

int128:
    cli
    pusha
    push gs
    push fs
    push ds
    push es
    call exception_syscall
    pop es
    pop ds
    pop fs
    pop gs
    popa
    sti
    iret
