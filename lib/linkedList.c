#include "linkedList.h"
#include "kmalloc.h"

unsigned int* createLinkedList(){
   unsigned int* head = (unsigned int*) kmalloc(2*sizeof(int));
   head[0] = 0;
   head[1] = 0;
   return head;
}

void insertLinkedList(unsigned int* address, void* value){
   unsigned int* next = address;
   while(next[0] != 0){
      next = (unsigned int*) next[0];
   }
   unsigned int* newBox = (unsigned int*) kmalloc(2*sizeof(int));
   next[0] = (unsigned int) newBox;
   newBox[0] = 0;
   newBox[1] = (unsigned int) value;
}

void* removeLinkedList(unsigned int* address, int (*f)(void*)){
   unsigned int* next = address;
   unsigned int* last = next;
   while(next[0] != 0){
      last = next;
      next = (unsigned int*) next[0];
      if((*f)((void*) next[1])){
         /* Remove element */
         void* returnValue = (void*) next[1];
         last[0] = next[0];
         /* TODO FREE*/
         return returnValue;
      }
   }
   return 0;
}

int sizeLinkedList(unsigned int* address){
   int i = 0;
   unsigned int* next = address;
   while(next[0] != 0){
      next = (unsigned int*) next[0];
      i++;
   }
   return i;
}
