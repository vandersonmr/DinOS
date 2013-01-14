#ifndef _X86_H_
#define _X86_H_

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

extern void zero_division(void);

void idt_setup(unsigned int);

extern void exception0(void);

#endif
