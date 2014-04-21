#ifndef _KMALLOC_H_
#define _KMALLOC_H_

#define INIT_DMEM 0xA00000 //10mb

unsigned int kmalloc(int);

unsigned int malloc(int);
void free(unsigned int);

#endif
