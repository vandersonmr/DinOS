/* Código responsável por buscar informações da CPU e checar suas capacidades */
#include "cpuid.h" 

void doCpuid(unsigned info, char *eax, char *ebx, 
				char *ecx, char *edx){
	asm volatile("cpuid"
		      :"=a"(*eax),
		      "=b"(*ebx),
                      "=d"(*edx),
                      "=c"(*ecx)
		      :"a"(info));
}

// Carrega o CPU's manufacturer ID string na estrutura cid 
void load_vendor_id(struct cpuid* cid){

	doCpuid(0,(char*) &cid->id,&cid->vendor_id[0],
				&cid->vendor_id[4],
				&cid->vendor_id[8]);
	
}

// Preenche os campos familyInfo e featureInfo
void load_family_feature_info(struct cpuid* cid){

	int *aux = 0;
	doCpuid(1,(char*) &cid->family_info,(char*) aux,
				(char*) &cid->feature_info[0],
				(char*) &cid->feature_info[1]);
	
}

void load_extended_info(struct cpuid* cid){

	int *aux = 0;
	doCpuid(0x80000001,(char*) aux,(char*) aux,
				(char*) &cid->Extended_info[1],
				(char*) &cid->Extended_info[2]);
	
}

void load_memory_size(struct cpuid* cid) {
  unsigned int* memp = (unsigned int*) 0x7000;
  cid->memory_size = (((*memp) * 65536) + 16777216) / (1024*1024);
}

// Carrega todos os dados do CPU na estrutura cid
void load_cpu_info(struct cpuid* cid){
	load_vendor_id(cid);
	load_family_feature_info(cid);
	load_extended_info(cid);
  load_memory_size(cid);
}

// AMD64 compliant processors have the longmode-capable-bit turned on in the extended feature
int has_longmode_support(struct cpuid* cid){
	return *(cid->Extended_info) & 0x20000000;
}

