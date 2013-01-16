section .text

; http://forum.osdev.org/viewtopic.php?t=12268

global inb
global insword
global outb
global waitdisk
global readsector
global readsegment

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

    push eax

    push 0x1f7
L1:
    call inb
    and eax, 0xe0
    sub eax, 0x40
    jnz L1

    add esp, 4

    pop eax

    leave
    ret


;void readsector(void *addr, int offset);
readsector:
    push ebp
    mov ebp, esp

    push edx
    push eax

    call waitdisk

    ; outb(0x1F2, 1);
    push 0x01
    push 0x1f2
    call outb
    add esp, 8

    ;outb(0x1F3, offset);
    mov edx, [ebp + 12]     ; mov edx, offset
    push edx
    push 0x1f3
    call outb
    add esp, 8

    ;outb(0x1F4, offset >> 8);
    mov eax, edx
    shr eax, 8
    push eax
    push 0x1f4
    call outb
    add esp, 8

    ;outb(0x1F5, offset >> 16);
    mov eax, edx
    shr eax, 16 
    push eax
    push 0x1f5
    call outb
    add esp, 8

    ;outb(0x1F6, (offset >> 24) | 0xE0);
    mov eax, edx
    shr eax, 24 
    or eax, 0xe0
    push eax
    push 0x1f6
    call outb
    add esp, 8

    ;outb(0x1F7, 0x20);
    push 0x20
    push 0x1f7
    call outb
    add esp, 8

    call waitdisk

    ;insword(0x1F0, addr, SECTORSIZE/2);
    mov eax, [ebp + 8]
    push 256
    push eax
    push 0x1f0
    call insword
    add esp, 12

    pop eax
    pop edx

    leave
    ret


;void readsegment(void *addr, int offset, int num);
readsegment:
    push ebp
    mov ebp, esp

    push eax
    push ebx
    push ecx

    mov eax, [ebp + 8]  ; mov eax, addr
    mov ebx, [ebp + 12] ; mov ebx, offset
    mov ecx, [ebp + 16] ; mov ecx, num

LRS1:
    push ebx
    push eax
    call readsector
    add esp, 8
    add eax, 512
    add ebx, 1
    dec ecx
    jnz LRS1

    pop ecx
    pop ebx
    pop eax

    leave
    ret
