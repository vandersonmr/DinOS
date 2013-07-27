#include "idt.h"
#include "screen.h"
#include "string.h"
#include "cpuid.h"
#include "paging.h"

struct cpuid *cpuinfo; 

struct idt_entry idt_entries[256];
struct idt idt_table;

int main() { 
    paging_init();
    print("VM init. I don't know WHY, but it's working so don't change this shit!\n",2,0);
	
    print("Kernel Loaded\n",3, 0);
    
    memset(idt_entries, 0, sizeof(struct idt_entry) * 256);

    idt_init(idt_entries, &idt_table);
    
    asm("int $0x80\n");	
      
    for(;;);

}
