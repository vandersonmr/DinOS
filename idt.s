section .text

global idt_setup

idt_setup:

    mov eax, [esp+4]
    lidt [eax]
    ret
