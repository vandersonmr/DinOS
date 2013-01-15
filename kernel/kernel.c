#include "idt.h"
#include "screen.h"
#include "cpuid.h"


struct cpuid *cpuinfo; 

int main() { 

    clearscreen();
    loadCpuInfo(cpuinfo);
    print("Hardware info: %s\nFamily feature flag: %b",2,0,cpuinfo->vendorID,cpuinfo->familyInfo);  
      
    for(;;);

}
