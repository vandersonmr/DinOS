#include "idt.h"

void interrupt_handler(struct registers regs) {

    if(regs.int_no == 0) {
        zero_division();
    }

}
