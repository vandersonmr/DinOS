#ifndef _CPUID_H_
#define _CPUID_H_
#include "paging.h"

struct cpuid {
	unsigned int id;
	char vendor_id[12];
	unsigned int family_info; //Processor Info Bits
	unsigned int feature_info[2]; //Processor feature bits
	unsigned int Extended_info[2]; //Extended Processor Info and Feature Bits
  unsigned int memory_size;
};

void load_cpu_info(struct cpuid*);
int has_longmode_support(struct cpuid*);

#endif
