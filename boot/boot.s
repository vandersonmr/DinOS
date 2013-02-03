[bits 16]
[org 0x7c00]

start16:

    ; Carregando o codigo do init.c do disco via BIOS interrupt
    ; Substituido por IO via IO ports la no modo protegido
    ; http://wiki.osdev.org/ATA_in_x86_RealMode_(BIOS)#Reading_sectors_with_a_CHS_address
    ;mov ah, 2
    ;mov al, 20   ; numero de setores a serem lidos
    ;mov ch, 0
    ;mov cl, 2
    ;mov dh, 0
    ;mov bx, 0x00
    ;mov dl, 0x80
    ;int 0x13


    cli

    xor ax, ax
    mov ds, ax

    lgdt [gdtdesc]
    ; Habilitando modo protegido
    mov eax, cr0
    or eax, 1
    mov cr0, eax

    ; Esse salto atualiza o CS e limpa o pipeline
    jmp 0x08:start32

[BITS 32]
start32:


    mov ax, 0x10
    mov ds, ax
    mov ss, ax

    mov esp, 0x90000
    

    ; Mensagem de vitoria :D
    mov edi, 0xb8000 + 1920
    mov esi, string1
    mov ecx, [size1]

    xor eax, eax
L2:
    mov byte al, [esi]
    mov byte [edi], al
    inc edi
    mov byte [edi], 0x0a
    inc esi
    inc edi
    dec ecx
    jnz L2

    ;call enable_paging

    ; Carregando o init.bin na memória
    push 40
    push 2
    push 0x200
    call readsegment
    add esp, 12

    ; Salta para o código carregado do segundo setor do disco (init.c)
    jmp INIT


%include "lib/io.s"
%include "vm/paging.s"


INIT:
    call 0x1000



string1: db "Ao vivo diretamente do Modo Protegido"
size1: db 37

gdt:
nullsegment:
    dw 0x00, 0x00
    db 0x00, 0x00, 0x00, 0x00

codesegment:    
    dw 0xffff, 0x00
    db 0x00, 10011010b, 11001111b, 0x00

datasegment:    
    dw 0xffff, 0x00
    db 0x00, 10010010b, 11001111b, 0x00
gdtend:

gdtdesc:
    dw gdtend - gdt - 1
    dd gdt


times 510 - ($ - $$) db 0
dw 0xAA55
