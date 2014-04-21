#ifndef _KMALLOC_H_
#define _KMALLOC_H_

#define INIT_DMEM 0x2000000 //32mb

unsigned int kmalloc(int);

unsigned int malloc(int);
void free(unsigned int);

#endif
