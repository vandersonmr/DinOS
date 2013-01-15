section .text

global memcpy

memcpy:
    push ebp
    mov ebp, esp

    push edi
    push esi
    push ecx

    cld
    mov edi, [ebp + 8]
    mov esi, [ebp + 12]
    mov ecx, [ebp + 16]

    repnz movsb

    pop ecx
    pop esi
    pop edi

    leave
    ret
