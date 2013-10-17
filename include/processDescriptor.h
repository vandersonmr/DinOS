#ifndef _PROCESSDESCRIPTOR_H_
#define _PROCESSDESCRIPTOR_H_

#include "paging.h"
#include "mm.h"

unsigned long page_directory[1024] __attribute__ ((aligned (4096)));
page_table_t page_tables[page_directory_size];

typedef struct vm_block {
   unsigned long start;
   unsigned long end;
   int size;
   memory_block* real_memory_block;
   int inUse; // 0 to free virtual memory block
} vm_block;

unsigned int* free_vm_blocks;
unsigned int* inUse_vm_blocks;

#endif
