section .text

global inb
global outb

inb:
    push ebp
    mov ebp, esp

    push eax
    push edx
    xor eax, eax

    mov edx, [ebp + 8]
    in al, dx

    pop edx
    pop eax
    leave
    ret



outb:
    push ebp
    mov ebp, esp

    push eax
    push edx

    mov eax, [ebp + 8]
    mov edx, [ebp + 12]
    out dx, al

    pop edx
    pop eax
    leave
    ret
