#include "idt.h"
#include "mm.h"
#include "screen.h"
#include "string.h"
#include "cpuid.h"
#include "paging.h"
#include "linkedList.h"

struct cpuid *cpuinfo;

struct idt_entry idt_entries[256];
struct idt idt_table;

int main() {
    paging_init();
    print("VM init. I don't know WHY, but it's working so don't change this shit!\n");

    print("Kernel Loaded...\n");

    print("Let the carnage bagin!\n");

    memset(idt_entries, 0, sizeof(struct idt_entry) * 256);

    idt_init(idt_entries, &idt_table);
    memory_init(0,100);

    int a = 0;
    int b = 10;
    unsigned int* list = create_linked_list();
    insert_linked_list(list,(void*)&a);
    insert_linked_list(list,(void*)&b);
    int size = size_linked_list(list);

    print("Tamanho da lista:  %d \n", size);
    
    asm("int $0x80\n");

    for(;;);

}
