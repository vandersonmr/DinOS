all: disk build init libs kernel make

disk:
	dd if=/dev/zero of=disk.img bs=1m count=10 > /dev/null 2>&1

build:
	nasm -fbin -o boot.o boot.s

make:
	/opt/local/bin/i386-elf-ld -i -Ttext 0x10000 kernel.o screen.o -o kernel.img
	/opt/local/bin/i386-elf-ld -S -e init -T linker.ld init.o idt.o exception_handler.o exceptions.o screen.o -o init.bin
	dd if=boot.o of=disk.img bs=512 count=1 conv=notrunc > /dev/null 2>&1
	dd if=init.bin of=disk.img bs=512 seek=1 conv=notrunc > /dev/null 2>&1
	dd if=kernel.img of=disk.img bs=512 seek=32 conv=notrunc > /dev/null 2>&1

init:
	/opt/local/bin/i386-elf-gcc -Wall -Os -c init.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
	/opt/local/bin/i386-elf-gcc -Wall -Os -c exceptions.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
	nasm -felf32 -o idt.o idt.s
	nasm -felf32 -o exception_handler.o exception_handler.s

libs: screen

screen:
	/opt/local/bin/i386-elf-gcc -Wall -Os -c screen.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

kernel:
	/opt/local/bin/i386-elf-gcc -Wall -Os -c kernel.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

clean:
	rm -rf *.o *.img *.bin
