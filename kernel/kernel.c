#include "idt.h"
#include "mm.h"
#include "screen.h"
#include "string.h"
#include "cpuid.h"
#include "paging.h"
#include "linkedList.h"
#include "cpuid.h"
#include "x86.h"
#include "serial.h"

struct cpuid *cpuinfo;

struct idt_entry idt_entries[256];
struct idt idt_table;

int main() {
    paging_init();
    print("VM init.\n");

    print("Kernel Loading...\n");

    print("Let the carnage bagin!\n");

    print("Starting COM1 serial port\n");
    serial_setup();
    serial_write_byte(0x41);

    memset(idt_entries, 0, sizeof(struct idt_entry) * 256);

    struct cpuid info;
    load_cpu_info(&info);
    
    print("Memory size: %d\n", info.memory_size); 

    idt_init(idt_entries, &idt_table);
    memory_init(0x1000000,info.memory_size*1024*1024); 
    memory_block* m = get_free_memory(10);

    asm("int $0x80\n");

    for(;;);

}
