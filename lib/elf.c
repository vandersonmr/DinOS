#include "string.h"
#include "elf.h"

void elf_read_eheader(void *addr, Elf32_Ehdr *header) {

    memcpy((void *)header, addr, sizeof(Elf32_Ehdr));

}
