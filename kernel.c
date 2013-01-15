#include "idt.h"
#include "screen.h"

char x;
int version;

int main() {

    version=12;
    x = '*';
    char virgula = ',';

    printk("The Fucking%c Kernel %c versao: %d", 15, 0,virgula,x,version);

    for(;;);

}
