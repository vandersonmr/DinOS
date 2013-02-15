#ifndef _PAGING_H_
#define _PAGING_H_

unsigned int page_directory[1024];
unsigned int page_table[1024];

void enable_paging(unsigned int);
void paging_init(void);
#endif
