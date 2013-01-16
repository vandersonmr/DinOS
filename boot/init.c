#include "x86.h"
#include "screen.h"
#include "string.h"
#include "elf.h"

void init() {

    unsigned char *kernel = (unsigned char *) 0xff000;

    int (*kernel_code)() = (int(*)()) 0x100000;

    int i = 100;

    Elf32_Ehdr elf;

    clearscreen();

    print("Kernel Loading", 0, 0);

    readsegment((void *)kernel, 64, 2048);

    elf_read_eheader((void *)kernel, &elf);

    unsigned char *copy = (unsigned char *) 0x200000;
    unsigned char *from = (unsigned char *) 0x101000;

    memcpy((void *)copy, (void *)from, 2048);

    kernel_code();

    for(;;) {
    }

}
