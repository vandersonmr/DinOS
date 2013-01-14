#include "x86.h"
#include "screen.h"

static void set_idt_entry(unsigned char, struct idt_entry *, unsigned int,
        unsigned short, unsigned char);

void init() {

    struct idt_entry idt_entries[256];
    struct idt idt_tab;

    char *v = (char *) 0xb8000;

    char l = 0x41;
    unsigned char z = 0;


    idt_tab.limit = sizeof(struct idt_entry) * 256 - 1;
    idt_tab.base = (unsigned int) idt_entries;

    //for(z=0;z<256;z++) set_idt_entry(z, idt_entries, (unsigned int) exception0, 0x08, 0x8e);

    /*
    set_idt_entry(0, idt_entries, (unsigned int) exception0, 0x08, 0x8e);
    set_idt_entry(1, idt_entries, (unsigned int) exception1, 0x08, 0x8e);
    set_idt_entry(2, idt_entries, (unsigned int) exception2, 0x08, 0x8e);
    set_idt_entry(3, idt_entries, (unsigned int) exception3, 0x08, 0x8e);
    set_idt_entry(4, idt_entries, (unsigned int) exception4, 0x08, 0x8e);
    set_idt_entry(5, idt_entries, (unsigned int) exception5, 0x08, 0x8e);
    set_idt_entry(6, idt_entries, (unsigned int) exception6, 0x08, 0x8e);
    set_idt_entry(7, idt_entries, (unsigned int) exception7, 0x08, 0x8e);
    */

    idt_setup((unsigned int)&idt_tab);

    print("Mensagem de dentro do arquivo init.c", 20, 0);

    for(;;) {
    /*
        *v++ = l;
        *v++ = 0x07;
        l++;
        if(l > 0x5a) l = 0x41;
    */
    }

}

static void set_idt_entry(unsigned char num, struct idt_entry *tab, unsigned int base,
        unsigned short sel, unsigned char flags) {

    tab[num].base_low = ((unsigned int)base) & 0xffff;
    tab[num].base_high = ((unsigned int)base >> 16) & 0xffff;
    tab[num].seg_selector = sel;
    tab[num].zero = 0;
    tab[num].flags = flags;

}
