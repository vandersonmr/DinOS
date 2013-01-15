#include "idt.h"
#include "screen.h"

int x;

int main() {

    x = 100;

    print("The Fucking Kernel", 15, 0);

    for(;;);

}
