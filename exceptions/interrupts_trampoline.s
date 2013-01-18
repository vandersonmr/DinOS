section .text

extern interrupts_common

global int0

int0:
    cli
    push byte 0
    push byte 0
    jmp interrupts_common
