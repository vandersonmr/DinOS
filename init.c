#include "x86.h"
#include "screen.h"

static void readsector(void *, int);
static void readsegment(void *, int, int);

void init() {

    unsigned char *kernel = (unsigned char *) 0xff000;

    int (*kernel_code)() = 0x100000;

    int i = 100;

    readsegment((void *)kernel, 32, 2048);

    unsigned char *copy = (unsigned char *) 0x200000;
    unsigned char *from = (unsigned char *) 0x101000;

    for(i=0;i<100;i++) {
        *copy = *from;
        copy++;
        from++;

    }
    
    clearscreen();
    print("Mensagem de dentro do arquivo " __FILE__, 0, 0);

    //readsector((void *)kernel, 32);

    kernel_code();

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
        addr += SECTORSIZE;
        offset += 1;
    }



}
