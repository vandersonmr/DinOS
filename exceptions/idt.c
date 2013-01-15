#include "idt.h"

void idt_setup(unsigned int idt){
    //asm ("mov eax, [esp+4]"
    //"lidt [eax]");
}

void set_idt_entry(unsigned char num, struct idt_entry *tab, unsigned int base,
        unsigned short sel, unsigned char flags) {

    tab[num].base_low = ((unsigned int)base) & 0xffff;
    tab[num].base_high = ((unsigned int)base >> 16) & 0xffff;
    tab[num].seg_selector = sel;
    tab[num].zero = 0;
    tab[num].flags = flags;

}
