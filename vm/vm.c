#include "paging.h"
#include "string.h"
#define flagsPDE 0x3
#define flagsPTE 0x3

void paging_init(void) {

    memset(page_directory, 0, sizeof(unsigned long) * 1024);
    memset(page_table, 0, sizeof(unsigned long) * 1024);
    
    
    int i;
    for(i=0;i<1024;i++){
        page_table[i] = (i*4096) | flagsPTE;	
	page_directory[i] = 0;
    }
 
    page_directory[0] = (unsigned long) page_table | flagsPDE;
    
    enable_paging((unsigned long)page_directory);
}
