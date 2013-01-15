all: buildimage

buildimage: boot.o init.o kernel.o disk.img
	dd if=boot.o of=disk.img bs=512 count=1 conv=notrunc > /dev/null 2>&1
	dd if=init.bin of=disk.img bs=512 seek=1 conv=notrunc > /dev/null 2>&1
	dd if=kernel.img of=disk.img bs=512 seek=32 conv=notrunc > /dev/null 2>&1

disk.img:
	dd if=/dev/zero of=disk.img bs=1m count=10 > /dev/null 2>&1

boot.o: boot/boot.s
	nasm -fbin -o boot.o boot/boot.s

init.o: boot/init.c string.o exceptions.o exception_handler.o io.o screen.o include/x86.h
	/opt/local/bin/i386-elf-gcc -Wall -g -O0 -I./include -c boot/init.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
	/opt/local/bin/i386-elf-ld -T boot/init.ld -o init.bin

exceptions.o: exceptions/exceptions.c
	/opt/local/bin/i386-elf-gcc -Wall -g -O0 -c exceptions/exceptions.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

idt.o: exceptions/idt.c include/idt.h
	/opt/local/bin/i386-elf-gcc -Wall -g -O0 -I./include -c exceptions/idt.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

exception_handler.o: exceptions/exception_handler.s
	nasm -felf32 -g -o exception_handler.o exceptions/exception_handler.s

io.o: lib/io.s
	nasm -felf32 -g -o io.o lib/io.s

string.o: lib/string.s include/string.h
	nasm -felf32 -g -o string.o lib/string.s

screen.o: lib/screen.c include/screen.h
	/opt/local/bin/i386-elf-gcc -Wall -O0 -g -I./include -c lib/screen.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

kernel.o: kernel/kernel.c lib/screen.c
	/opt/local/bin/i386-elf-gcc -Wall -g -O0 -I./include -c kernel/kernel.c -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
	/opt/local/bin/i386-elf-ld -T kernel/kernel.ld -o kernel.img

clean:
	rm -rf *.o *.img *.bin
