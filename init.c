#include "x86.h"
#include "screen.h"

static void readsector(void *, int);
static void readsegment(void *, int, int);

void init() {

    unsigned char *kernel = (unsigned char *) 0x100000;
    
    clearscreen();
    print("Mensagem de dentro do arquivo " __FILE__, 0, 0);

    readsegment((void *)kernel, 32, 1);

    for(;;) {
    }

}

static void readsector(void *addr, int offset) {

    waitdisk();

    outb(0x1F2, 1);
    outb(0x1F3, offset);
    outb(0x1F4, offset >> 8);
    outb(0x1F5, offset >> 16);
    outb(0x1F6, (offset >> 24) | 0xE0);
    outb(0x1F7, 0x20);

    waitdisk();

    insword(0x1F0, addr, SECTORSIZE/2);

}

static void readsegment(void *addr, int offset, int num) {

    for(; num > 0; num--) {
        readsector(addr, offset);
        addr += 2;
        offset += 2;
    }



}
