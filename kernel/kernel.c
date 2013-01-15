#include "idt.h"
#include "screen.h"

int x;

char nome[123];

void *n = 0x1000;

int main() {

    x = 100;

    print("The Fucking Kernel", 15, 0);

    for(;;);

}
