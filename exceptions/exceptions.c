void zero_division(void) {

    char *v = (char *) 0xb8000;

    *v = 'D';
    v++;
    *v = 0x0a;
    v++;
    *v = 'i';
    v++;
    *v = 0x0a;
    v++;
    *v = 'v';
    v++;
    *v = 0x0a;
    v++;
    *v = ' ';
    v++;
    *v = 0x0a;
    v++;
    *v = 'Z';
    v++;
    *v = 0x0a;
    v++;
    *v = 'e';
    v++;
    *v = 0x0a;
    v++;
    *v = 'r';
    v++;
    *v = 0x0a;
    v++;
    *v = '0';
    v++;
    *v = 0x0a;

}
