CC = /opt/local/bin/i386-elf-gcc
LD = /opt/local/bin/i386-elf-ld

all: buildimage

buildimage: boot.o init.o kernel.o disk.img
	dd if=boot.o of=disk.img bs=512 count=1 conv=notrunc > /dev/null 2>&1
	dd if=init.bin of=disk.img bs=512 seek=1 conv=notrunc > /dev/null 2>&1
	dd if=kernel.img of=disk.img bs=512 seek=32 conv=notrunc > /dev/null 2>&1

disk.img:
	dd if=/dev/zero of=disk.img bs=1m count=10 > /dev/null 2>&1

boot.o: boot.s
	nasm -fbin -o boot.o boot.s

init.o: init.c exceptions.o exception_handler.o io.o screen.o
	$(CC) -Wall -g -O0 -c init.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
	$(LD) -T init.ld -o init.bin

exceptions.o: exceptions.c
	$(CC) -Wall -g -O0 -c exceptions.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

idt.o: idt.c idt.h
	$(CC) -Wall -g -O0 -c idt.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

exception_handler.o exception_handler.s:
	nasm -felf32 -g -o exception_handler.o exception_handler.s

io.o: io.s
	nasm -felf32 -g -o io.o io.s

screen.o: screen.c screen.h
	$(CC) -Wall -O0 -g -c screen.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

kernel.o: kernel.c
	$(CC) -Wall -Os -c kernel.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
	$(LD) -i -Ttext 0x10000 kernel.o screen.o -o kernel.img

clean:
	rm -rf *.o *.img *.bin
