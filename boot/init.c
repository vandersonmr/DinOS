#include "x86.h"
#include "string.h"
#include "screen.h"
#include "paging.h"

unsigned int *memp = (unsigned int *) 0x7000;

char dinLogo[17][85] = 
{{"DDDDDDDDDDDDD          iiii                        OOOOOOOOO        SSSSSSSSSSSSSSS \n"},
{"D::::::::::::DDD      i::::i                     OO:::::::::OO    SS:::::::::::::::S\n"},
{"D:::::::::::::::DD     iiii                    OO:::::::::::::OO S:::::SSSSSS::::::S\n"},
{"DDD:::::DDDDD:::::D                           O:::::::OOO:::::::OS:::::S     SSSSSSS\n"},
{"  D:::::D    D:::::D iiiiiiinnnn  nnnnnnnn    O::::::O   O::::::OS:::::S            \n"},
{"  D:::::D     D:::::Di:::::in:::nn::::::::nn  O:::::O     O:::::OS:::::S            \n"},
{"  D:::::D     D:::::D i::::in::::::::::::::nn O:::::O     O:::::O S::::SSSS         \n"},
{"  D:::::D     D:::::D i::::inn:::::::::::::::nO:::::O     O:::::O  SS::::::SSSSS    \n"},
{"  D:::::D     D:::::D i::::i  n:::::nnnn:::::nO:::::O     O:::::O    SSS::::::::SS  \n"},
{"  D:::::D     D:::::D i::::i  n::::n    n::::nO:::::O     O:::::O       SSSSSS::::S \n"},
{"  D:::::D     D:::::D i::::i  n::::n    n::::nO:::::O     O:::::O            S:::::S\n"},
{"  D:::::D    D:::::D  i::::i  n::::n    n::::nO::::::O   O::::::O            S:::::S\n"},
{"DDD:::::DDDDD:::::D  i::::::i n::::n    n::::nO:::::::OOO:::::::OSSSSSSS     S:::::S\n"},
{"D:::::::::::::::DD   i::::::i n::::n    n::::n OO:::::::::::::OO S::::::SSSSSS:::::S\n"},
{"D::::::::::::DDD     i::::::i n::::n    n::::n   OO:::::::::OO   S:::::::::::::::SS \n"},
{"DDDDDDDDDDDDD        iiiiiiii nnnnnn    nnnnnn     OOOOOOOOO      SSSSSSSSSSSSSSS   \n"},
{"                                                                                    \n"},};

void init() {

    unsigned char *kernel = (unsigned char *) 0xffffff;
    unsigned char *text   = (unsigned char *) 0x100000;
    unsigned char *rodata = (unsigned char *) 0x200000;
    unsigned char *data   = (unsigned char *) 0x300000;

    mem = *memp;
    int (*kernel_code)() = (int(*)()) text;

    clearscreen();
    
    print("Kernel Loading...");
    print(" ");
    int i;//,j,p,t;
    for(i=0;i<19;i++){
	    print(dinLogo[i]);
	    //for(j=0;j<32766;j++){ for(p=0;p<300;p++){ t=p*j; } }
    }	

    readsegment((void *)kernel, 64, 32768);

    memcpy((void *)text  ,   (void *)kernel + 0x2000, 0x100000);
    memcpy((void *)rodata,   (void *)kernel + 0x4000, 0x100000);
    memcpy((void *)data  ,   (void *)kernel + 0x6000, 0x100000);
    clearscreen();

    kernel_code();


}
