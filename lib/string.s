section .text

global memcpy
global memset

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

memset:
    push ebp
    mov ebp, esp

    push edi
    push eax
    push ecx

    xor eax, eax
    mov edi, [ebp + 8]
    mov byte al, [ebp + 12]
    mov ecx, [ebp + 16]

    repnz stosb

    pop ecx
    pop eax
    pop edi

    leave
