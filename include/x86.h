#ifndef _X86_H_
#define _X86_H_

#define SECTORSIZE 512

/* IO functions */
unsigned char inb(unsigned short);
void outb(unsigned short, unsigned char);
void insword(int, void *, int);
void waitdisk(void);
void readsector(void *, int);
void readsegment(void *, int, int);

#endif
