#include "paging.h"
#include "string.h"

void paging_init(void) {

    int pde_index;
    int pte_index;

    memset(page_directory, 0, sizeof(unsigned int) * 1024);
    memset(page_table, 0, sizeof(unsigned int) * 1024);



}

int get_pde_from_address(unsigned int addr) {
    return ((addr >> 22) & 0x3ff);
}

int get_pte_from_address(unsigned int addr) {
    return ((addr >> 12) & 0x3ff);
}

int get_poffset_from_address(unsigned int) {
    return addr & 0xfff;
}
