section text

global exception0

exception0:

    cli
    mov eax, 0xb8000
    mov BYTE [eax], 0x41
    inc eax
    mov BYTE [eax], 0x0a
    sti

    iret
