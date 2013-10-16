#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

unsigned int* createLinkedList();
void insertLinkedList(unsigned int*,void*);
void* removeLinkedList(unsigned int*,int (*f)(void*));
int sizeLinkedList(unsigned int*);

#endif
