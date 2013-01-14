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

    char *video = (char *) VIDEO;
    int i;
    for(i=0;i<20000;i++)
	*video++= 0x0;

    return 0;

}
