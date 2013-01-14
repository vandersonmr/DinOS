#ifndef _CPUID_H_
#define _CPUID_H_


struct cpuid {
	unsigned int id;
	char vendorID[3][4];
	unsigned int familyInfo; //Processor Info Bits
	unsigned int featureInfo[2]; //Processor feature bits
	unsigned int ExtendedInfo[2]; //Extended Processor Info and Feature Bits
};

void loadCpuInfo(struct cpuid*);

int hasLongmodeSupport(struct cpuid*);

#endif
