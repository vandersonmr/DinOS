all:
	nasm -g -felf32 paging.s
	gcc vm.c -c -O0 -g -I../include/ -o vm.o
clean:
	rm paging.o
