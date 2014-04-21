#include "paging.h"
#include "string.h"
#include "mm.h"
#include "processDescriptor.h"
#define flagsPDE 0x3
#define flagsPTE 0x3

void paging_init(void) {

    memset(kpage_directory, 0, sizeof(unsigned long) * 1024);
    memset(kpage_tables, 0,
          sizeof(unsigned long) * 1024 * page_directory_size);

    int i,j,address = 0;
    for(j=0;j<page_directory_size;j++){

      for(i=0;i<1024;i++){
           kpage_tables[j].entry[i] = address | flagsPTE;
           address = address + 4096;
      }

      kpage_directory[j] = (unsigned long) &kpage_tables[j] | flagsPDE;
    }

    enable_paging((unsigned long)kpage_directory);
}

