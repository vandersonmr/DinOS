all: disk build init libs kernel make

disk:
	dd if=/dev/zero of=disk.img bs=1m count=10 > /dev/null 2>&1

build:
	nasm -fbin -o boot.o boot.s

make:
	/opt/local/bin/i386-elf-ld -i -Ttext 0x100000 kernel.o screen.o -o kernel.img
	/opt/local/bin/i386-elf-ld -i -Ttext 0x10000 init.o -o inittmp.o
	/opt/local/bin/i386-elf-objcopy -O binary -j .text inittmp.o init.bin
	dd if=boot.o of=disk.img bs=512 count=1 conv=notrunc > /dev/null 2>&1
	dd if=init.bin of=disk.img bs=512 seek=1 conv=notrunc > /dev/null 2>&1
	dd if=kernel.img of=disk.img bs=512 seek=16 conv=notrunc > /dev/null 2>&1

init:
	/opt/local/bin/i386-elf-gcc -c init.c -nostdlib

libs: screen

screen:
	/opt/local/bin/i386-elf-gcc -c screen.c -nostdlib

kernel:
	/opt/local/bin/i386-elf-gcc -c kernel.c -nostdlib

clean:
	rm -rf *.o *.img *.bin
