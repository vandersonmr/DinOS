#ifndef _PAGING_H_
#define _PAGING_H_

unsigned long page_directory[1024] __attribute__ ((aligned (4096)));;
unsigned long page_table[1024] __attribute__ ((aligned (4096)));;

void enable_paging(unsigned int);
void paging_init(void);
#endif
