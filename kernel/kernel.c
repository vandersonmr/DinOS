#include "idt.h"
#include "screen.h"
#include "string.h"
#include "cpuid.h"
#include "paging.h"
#include "linkedList.h"
#include "x86.h"
#include "serial.h"

struct cpuid *cpuinfo;

struct idt_entry idt_entries[256];
struct idt idt_table;

int main() {
    paging_init();
    print("VM init. I don't know WHY, but it's working so don't change this shit!\n");

    print("Kernel Loaded...\n");

    print("Let the carnage bagin!\n");

    print("Starting COM1 serial port\n");
    serial_setup();
    serial_write_byte(0x41);

    memset(idt_entries, 0, sizeof(struct idt_entry) * 256);

    idt_init(idt_entries, &idt_table);

    int a = 0;
    int b = 10;
    unsigned int* list = createLinkedList();
    insertLinkedList(list,(void*)&a);
    insertLinkedList(list,(void*)&b);
    int size = sizeLinkedList(list);

    print("Tamanho da lista:  %d \n",size);

    asm("int $0x80\n");

    for(;;);

}
