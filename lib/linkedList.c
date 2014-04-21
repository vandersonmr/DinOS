#include "linkedList.h"
#include "kmalloc.h"

unsigned int* create_linked_list(){
   unsigned int* head = (unsigned int*) kmalloc(2*sizeof(int));
   head[0] = 0;
   head[1] = 0;
   return head;
}

void insert_linked_list(unsigned int* address, void* value){
   unsigned int* next = address;
   while(next[0] != 0){
      next = (unsigned int*) next[0];
   }
   unsigned int* new_box = (unsigned int*) kmalloc(2*sizeof(int));
   next[0]   = (unsigned int) new_box;
   new_box[0] = 0;
   new_box[1] = (unsigned int) value;
}

void* remove_linked_list(unsigned int* address, int (*f)(void*)){
   unsigned int* next = address;
   unsigned int* last = next;
   while(next[0] != 0){
      last = next;
      next = (unsigned int*) next[0];
      if((*f)((void*) next[1])){
         /* Remove element */
         void* return_value = (void*) next[1];
         last[0] = next[0];
         /* TODO FREE*/
         return return_value;
      }
   }
   return 0;
}

int size_linked_list(unsigned int* address){
   int i = 0;
   unsigned int* next = address;
   while(next[0] != 0){
      next = (unsigned int*) next[0];
      i++;
   }
   return i;
}
