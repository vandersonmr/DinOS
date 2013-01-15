section .text

global inb
global insword
global outb
global waitdisk

;unsigned char inb(unsigned short);
inb:
    push ebp
    mov ebp, esp

    push edx
    xor eax, eax

    mov edx, [ebp + 8]
    in al, dx

    pop edx
    leave
    ret


;void outb(unsigned short, unsigned char);
outb:
    push ebp
    mov ebp, esp

    push eax
    push edx

    xor eax, eax
    xor edx, edx

    mov edx, [ebp + 8]
    mov eax, [ebp + 12]
    out dx, al

    pop edx
    pop eax
    leave
    ret



;void insword(int, void *, int);    
insword:
    push ebp
    mov ebp, esp

    push ecx
    push edi
    push edx

    mov edx, [ebp + 8]
    mov edi, [ebp + 12]
    mov ecx, [ebp + 16]

    cld
    repnz insw

    pop edx
    pop edi
    pop ecx

    leave
    ret



;void waitdisk(void);
waitdisk:
    push ebp
    mov ebp, esp

    push 0x1f7
L1:
    call inb
    and eax, 0xe0
    sub eax, 0x40
    jnz L1

    add esp, 4

    leave
    ret
