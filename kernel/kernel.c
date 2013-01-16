#include "idt.h"
#include "screen.h"
#include "cpuid.h"


struct cpuid *cpuinfo; 

int i = 10;

int main() { 

    print("Kernel Loaded\n",1, 0);

    loadCpuInfo(cpuinfo);

    print("Hardware info: %s\nFamily feature flag: %b",2,0,cpuinfo->vendorID,cpuinfo->familyInfo);  

      
    for(;;);

}
