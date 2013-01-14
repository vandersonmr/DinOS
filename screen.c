#include "screen.h"

#define VIDEO 0xB8000

int print(const char *string, int x, int y) {

    char *video = ((char *) VIDEO) + 160 * x + y;

    while(*string != 0) {
        *video++ = *string++;
        *video++ = 0x0a;
    }

    return 0;

}

void clearscreen() {

    //const char *video = (const char *) VIDEO;

}
