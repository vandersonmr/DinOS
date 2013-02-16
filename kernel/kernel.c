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

    print("Kernel Loaded\n",2, 0);

    memset(idt_entries, 0, sizeof(struct idt_entry) * 256);

    idt_init(idt_entries, &idt_table);

     unsigned int *i;
     unsigned char b;
     for(i = 0x500000; i < (64*1024*1024) ; i++) {
        b = (unsigned char) *i;
     }

    int a = 0;

    a = a/a;

    asm("int $0x80\n");

    asm("int3\n");


    loadCpuInfo(cpuinfo);

    print("Hardware info: %s\nFamily feature flag: %b",2,0,cpuinfo->vendorID,cpuinfo->familyInfo);  

      
    for(;;);

}
