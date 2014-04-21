all:
	nasm -g -felf32 paging.s
	clang -m32 vm.c -c -O0 -g -I../include/ -o vm.o
clean:
	rm -rf paging.o vm.o
