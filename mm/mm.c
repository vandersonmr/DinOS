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

int fitnessSize = 0;
int fit(void* m) {
  return ((memory_block*)m)->size >= fitnessSize;  
}

memory_block* get_free_memory(int size){  
  fitnessSize = size;
  memory_block* m = remove_linked_list(free_memory_blocks, fit);
  if(m->size > size) {
    memory_block* rest = (memory_block*) kmalloc(sizeof(memory_block));
    rest->start = m->start;
    rest->end   = m->end  - size;
    rest->size  = m->size - size;
    rest->inUse = 0;
    insert_linked_list(free_memory_blocks, (void*)m);

    m->size  = size;
    m->start = m->start + size;
  }
  m->inUse = 1;
  return m;
}

void free_memory(memory_block* inUseMemory){
  inUseMemory->inUse = 0;
  insert_linked_list(free_memory_blocks, inUseMemory); 
}
