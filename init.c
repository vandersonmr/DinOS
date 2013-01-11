void init() {

    char *v = (char *) 0xb8000;

    char l = 0x41;

    for(;;) {
        *v++ = l;
        *v++ = 0x07;
        l++;
        if(l > 0x5a) l = 0x41;
    }

}
