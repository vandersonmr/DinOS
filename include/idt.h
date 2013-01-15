#ifndef _IDT_H_
#define _IDT_H_

struct idt_entry {

    unsigned short base_low;
    unsigned short seg_selector;
    unsigned char zero;
    unsigned char flags;
    unsigned short base_high;

} __attribute__((packed));

struct idt {

    unsigned short limit;
    unsigned int base;

} __attribute__((packed));

static void set_idt_entry(unsigned char, struct idt_entry *, unsigned int,
        unsigned short, unsigned char);

void idt_setup(unsigned int);

#endif
