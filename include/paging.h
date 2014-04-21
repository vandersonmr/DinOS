#ifndef _PAGING_H_
#define _PAGING_H_

#define page_directory_size 64

unsigned int mem;
unsigned long kpage_directory[1024] __attribute__ ((aligned (4096)));

typedef struct page_table_t {
   unsigned long entry[1024];
} page_table_t __attribute__ ((aligned (4096)));

page_table_t kpage_tables[page_directory_size];

void enable_paging(unsigned int);
void paging_init(void);
#endif
