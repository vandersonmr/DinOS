#include "string.h"

void exception_zero(void) { 
    /*If your kernel issued a division by zero, trying to return to the 'div'
     	instruction will only trigger the exception one more time (yeah! altogether, now :) 
     	http://wiki.osdev.org/Exceptions */
    print("Ocorreu uma divisao por zero! ", 11, 0);
    /* O return volta para a instrução do div. E por isso volta a dar erro.
	Não seria certo avançar para próxima instrução porque é um erro grave 
	e que não deveria ocorrer no kernel.*/
    while(1){}; /* aqui deveria abortar o boot.
			No futuro, se causado por um processo, aqui deverá ter 
			uma função para abortar o processo (que gerou o erro) 
			e chamar um outro processo para ser executado.*/
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
