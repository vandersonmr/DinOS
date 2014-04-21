#include "mm.h"
#include "kmalloc.h"
#include "linkedList.h"
#include "screen.h"

void memory_init(unsigned int start,unsigned int end){
  print("Init memory blocks...");
  memory_block* memory = (memory_block*) kmalloc(sizeof(memory_block));

  memory->start = start;
  memory->end   = end;
  memory->size  = end - start;
  memory->inUse = 0;

  free_memory_blocks = create_linked_list();
  insert_linked_list(free_memory_blocks, (void*)memory);
}

memory_block get_free_memory(int size){  
}

void free_memory(memory_block inUseMemory){
}
