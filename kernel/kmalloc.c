#include "kmalloc.h"

unsigned int initial_memory = INIT_DMEM;

unsigned int kmalloc(int size) {

    unsigned int mem = initial_memory;

    //size = size - (size % 4096);
    //size += 4096;

    initial_memory += size;
    return mem;

}

