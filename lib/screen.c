
typedef char *va_list;

#define next_arg(p, type) p=p+sizeof(type);

#define printc(c,video) *video++ = c; *video++=0x0a;

#define VIDEO 0xB8000


int getInt(char *p){
	int* i = (int*)p;
	return (i[0]);
}

char* printint( int value, char * video, int base)
{
    int negativo = (base==10) & (value < 0);
    char *p;
    char *t;
    t=p;

    do
    {
        *p++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    } while ( value );

    if(negativo){
    	printc('-',video);
    }

    while(p-- != t){
	printc(*p,video);
    }

    return video;

}

void print(const char *str,int x, int y,...){

	char *video = ((char *) VIDEO) + 160 * x + y;

	char *s;

	
	va_list va = &y + 1;
	while(*str != 0){
		if(*str != '%'){
			
			if(*str == 0x0a){
				int v = video - VIDEO;
				video+=160-(v-160*(v/160));
			}else{
	 	        	printc(*str,video);
			}			
			str++;
			


		}else {
		
			switch(*++str)
			{
				case 'd':
					video = printint(getInt(va),video,10);
					next_arg(va,int);
					break;
				case 'c':
					printc((char)*va,video);
					next_arg(va,int);
					break;
				case 'x':
					video = printint(getInt(va),video,16);
					next_arg(va,int);
					break;
				case 'b':
					video = printint(getInt(va),video,2);
					next_arg(va,int);
					break;
				case '%':
					printc('%',video);
					break;
				case 's':
					s = (char*) (getInt(va));
					while(*s != 0){
						printc((char)*s++,video);
					}
					next_arg(va,int);
					break;
				
			}
			
			str++;	
		}
	}
}




void clearscreen() {

    char *video = (char *) VIDEO;
    int i;
    for(i=0;i<20000;i++)
	*video++= 0x0;

}
