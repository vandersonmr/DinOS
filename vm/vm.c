#include "paging.h"
#include "string.h"
#define flagsPDE 0x3
#define flagsPTE 0x3

void paging_init(void) {

    memset(page_directory, 0, sizeof(unsigned long) * 1024);
    memset(page_tables, 0,
          sizeof(unsigned long) * 1024 * page_directory_size);

    int i,j,address = 0;
    for(j=0;j<page_directory_size;j++){

      for(i=0;i<1024;i++){
           page_tables[j].entry[i] = address | flagsPTE;
           address = address + 4096;
      }

      page_directory[j] = (unsigned long) &page_tables[j] | flagsPDE;
    }
    enable_paging((unsigned long)page_directory);
}



