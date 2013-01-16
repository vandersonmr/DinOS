#include "x86.h"
#include "string.h"
#include "screen.h"

void init() {

    unsigned char *kernel = (unsigned char *) 0xffffff;
    unsigned char *text = (unsigned char *) 0x100000;
    unsigned char *rodata = (unsigned char *) 0x200000;
    unsigned char *data = (unsigned char *) 0x300000;

    int (*kernel_code)() = (int(*)()) text;

    clearscreen();
    print("Kernel Loading...", 0, 0);

    readsegment((void *)kernel, 64, 18432);

    memcpy((void *)text, (void *)kernel + 0x1000, 0x100000);
    memcpy((void *)rodata, (void *)kernel + 0x2000, 0x100000);
    memcpy((void *)data, (void *)kernel + 0x3000, 0x100000);

    kernel_code();

}
