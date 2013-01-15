/* Código responsável por buscar informações da CPU e checar suas capacidades */

#include "cpuid.h"

void doCpuid(unsigned info, unsigned *eax, unsigned *ebx, 
				unsigned *ecx, unsigned *edx){
	asm volatile("cpuid"
		      :"=a"(*eax),
		      "=b"(*ebx),
                      "=d"(*edx),
                      "=c"(*ecx)
		      :"a"(info));
}
// Carrega o CPU's manufacturer ID string na estrutura cid 
void loadVendorID(struct cpuid* cid){

	doCpuid(0,&cid->id,cid->vendorID[0],cid->vendorID[2],cid->vendorID[1]);
	
}

// Preenche os campos familyInfo e featureInfo
void loadFamilyFeatureInfo(struct cpuid* cid){

	int *aux;
	doCpuid(1,&cid->familyInfo,aux,&cid->featureInfo[0],&cid->featureInfo[1]);
	
}

void loadExtendedInfo(struct cpuid* cid){

	int *aux;
	doCpuid(0x80000001,aux,aux,&cid->ExtendedInfo[1],&cid->ExtendedInfo[2]);
	
}

// Carrega todos os dados do CPU na estrutura cid
void loadCpuInfo(struct cpuid* cid){
	loadVendorID(cid);
	loadFamilyFeatureInfo(cid);
	loadExtendedInfo(cid);
}

// AMD64 compliant processors have the longmode-capable-bit turned on in the extended feature
int hasLongmodeSupport(struct cpuid* cid){
	return *(cid->ExtendedInfo) & 0x20000000;
}


