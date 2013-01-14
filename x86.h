#ifndef _X86_H_
#define _X86_H_

extern void zero_division(void);
extern void exception0(void);

/* IO functions */
unsigned char inb(unsigned short);
void outb(unsigned short, unsigned char);

#endif
