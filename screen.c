#define VIDEO 0xB8000

void print(const char *string, int x, int y) {

    char *video = (char *) VIDEO;

    while(*string != 0) {
        *video++ = *string++;
        *video++ = 0x0a;
    }

}

void clearscreen() {

    const char *video = (const char *) VIDEO;

}
