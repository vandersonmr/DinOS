#include "idt.h"
#include "screen.h"
#include "string.h"
#include "cpuid.h"


struct cpuid *cpuinfo; 

struct idt_entry idt_entries[256];
struct idt idt_table;

int main() { 

    print("Kernel Loaded\n",1, 0);

    memset(idt_entries, 0, sizeof(struct idt_entry) * 256);

    idt_init(idt_entries, &idt_table);

    int a = 0;

    unsigned char b = 0;

    asm("int3\n");

    a /= a;


    loadCpuInfo(cpuinfo);

    print("Hardware info: %s\nFamily feature flag: %b",2,0,cpuinfo->vendorID,cpuinfo->familyInfo);  

      
    for(;;);

}
