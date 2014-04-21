#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

unsigned int* create_linked_list();
void insert_linked_list(unsigned int*,void*);
void* remove_linked_list(unsigned int*,int (*f)(void*));
int size_linked_list(unsigned int*);

#endif
