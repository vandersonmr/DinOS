#include "screen.h"

typedef char *va_list;

#define next_arg(p, type) p=p+sizeof(type);

#define printc(c,video) *video++ = c; *video++=0x0a;

#define VIDEO 0xB8000


int print(const char *string, int x, int y) {

    char *video = ((char *) VIDEO) + 160 * x + y;

    while(*string != 0) {
        *video++ = *string++;
        *video++ = 0x0a;
    }

    return 0;

}





void printk(const char *str,int x, int y,...){

	char *video = ((char *) VIDEO) + 160 * x + y;

	int pos =0;
	va_list va = &y + 1;
	while(*str != 0){
		if(*str != '%'){
			
		
	 	        printc(*str,video);
			str++;

		}else {
		
			switch(*++str)
			{
				case 'd':
					video = printint(((int)*va),video,10);
					next_arg(va,int);
					break;
				case 'c':
					printc((char)*va,video);
					next_arg(va,int);
					break;
			}
			str++;	
		}
		pos++;
	}
}


void printint( int value, char * video, int base)
{
    char *p;
    char *t;
    t=p;
    do
    {
        *p++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    } while ( value );
    while(p-- != t){
	printc(*p,video);
    }

}

void clearscreen() {

    char *video = (char *) VIDEO;
    int i;
    for(i=0;i<20000;i++)
	*video++= 0x0;

}
