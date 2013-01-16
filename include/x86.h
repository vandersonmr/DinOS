#ifndef _X86_H_
#define _X86_H_

#define SECTORSIZE 512

extern void zero_division(void);
extern void exception0(void);

/* IO functions */
unsigned char inb(unsigned short);
void outb(unsigned short, unsigned char);
void insword(int, void *, int);
void waitdisk(void);
void readsector(void *, int);
void readsegment(void *, int, int);

#endif
