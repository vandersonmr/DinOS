#include "string.h"

void exception_zero(void) {
    print("Ocorreu uma divisao por zero!", 11, 0);
}

void exception_overflow(void) {
    print("Ocorreu um overflow!", 12, 0);
}

void exception_breakpoint(void) {
    print("Breakpoint exception!", 13, 0);
}

void exception_syscall(void) {
    print("INT 0x80 disparado!", 14, 0);
}

void exception_generalprotection(void) {
    print("#GP exception!", 15, 0);
}

void exception_pagefault(void) {
    print("Ocorreu uma falta de pagina!", 16, 0);
}

void exception_doublefault(void) {
    print("Ocorreu uma doublefault exception!", 17, 0);
}
