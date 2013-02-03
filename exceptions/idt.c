#include "idt.h"

void idt_setup(unsigned int idt){
    asm (
            "lidt (%0)\n"
            :
            :"r" (idt)
            :
        );
}

void idt_init(struct idt_entry *entries, struct idt *table) {

    table->limit = sizeof(struct idt_entry) * 256 - 1;
    table->base = (unsigned int) entries;

    set_idt_entry(0, entries, (unsigned int)int0, 0x08, 0x8e);
    set_idt_entry(3, entries, (unsigned int)int3, 0x08, 0x8e);
    set_idt_entry(4, entries, (unsigned int)int4, 0x08, 0x8e);
    set_idt_entry(8, entries, (unsigned int)int8, 0x08, 0x8e);
    set_idt_entry(13, entries, (unsigned int)int13, 0x08, 0x8e);
    set_idt_entry(14, entries, (unsigned int)int14, 0x08, 0x8e);
    set_idt_entry(0x80, entries, (unsigned int)int128, 0x08, 0x8e);

    idt_setup((unsigned int)table);

}

void set_idt_entry(unsigned char num, struct idt_entry *tab, unsigned int base,
        unsigned short sel, unsigned char flags) {

    tab[num].base_low = ((unsigned int)base) & 0xffff;
    tab[num].base_high = ((unsigned int)base >> 16) & 0xffff;
    tab[num].seg_selector = sel;
    tab[num].zero = 0;
    tab[num].flags = flags;

}
