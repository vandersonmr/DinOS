#include "paging.h"
#include "string.h"
#define flagsPDE 0x7
#define flagsPTE 0x7

void paging_init(void) {

    int pde_index;
    int pte_index;

    memset(page_directory, 0, sizeof(unsigned int) * 1024);
    memset(page_table, 0, sizeof(unsigned int) * 1024);
    
    page_directory[0] = set_p_flags((unsigned int)page_table,flagsPDE);
    
    int i;
    for(i=0;i<1024;i++){
        page_table[i] = set_p_flags(0x0+i*4096,flagsPTE);	
    }
 
    enable_paging((unsigned int)page_directory);
}

int set_p_flags(unsigned int addr,unsigned int flags){
    return ((addr << 12) | flags);
}

int get_pde_from_address(unsigned int addr) {
    return ((addr >> 22) & 0x3ff);
}

int get_pte_from_address(unsigned int addr) {
    return ((addr >> 12) & 0x3ff);
}

int get_poffset_from_address(unsigned int addr) {
    return addr & 0xfff;
}
