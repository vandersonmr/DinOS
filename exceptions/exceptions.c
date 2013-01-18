#include "string.h"

void exception_zero(void) {
    print("Ocorreu uma divisao por zero, seu filha da puta!", 10, 0);
}

void exception_overflow(void) {
    print("Ocorreu um overflow, seu filha da puta!", 11, 0);
}

void exception_breakpoint(void) {
    print("Tem um int3 no codigo, seu filha da puta!", 13, 0);
}
