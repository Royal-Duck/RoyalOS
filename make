#! /bin/bash

# build dir cleaning
rm -rf bin/*
mkdir -p bin/src/lib

# libs compilation
libs=""
for file in src/lib/*; do
	echo "BUILD PROCESS : compiling ${file} library ..."
	extention=${file##*.}
	error=0

	if [ "$extention" = "c" ]; then
		gcc -m32 -ostdlib -fno-stack-protector -fno-builtin -c $file -o "bin/${file}lib.o"
	
	elif [ "$extention" = "asm" ]; then
		nasm -f elf32 $file -o "bin/${file}lib.o"
	
	else
		>&2 echo -e "\033[0;31mERROR : ${file}, file format not recognized !\033[0m"
		error=1
	fi
	
	if [ $error = 0 ]; then
		libs="${libs} bin/${file}lib.o"
	fi

done

# kernel compilation
echo "BUILD PROCESS : compiling the kernel ..."
gcc -m32 -fno-stack-protector -fno-builtin -c src/kernel.c -o bin/kernel.o

# boot_header compilation
echo "BUILD PROCESS : compiling the boot header file (boot.s) ..."
nasm -f elf32 src/boot.s -o bin/boot.o

# system linking
echo "LINKING PROCESS : linking the kernel ..."
ld -m elf_i386 -T linker.ld -o RoyalOS/boot/kernel bin/boot.o bin/kernel.o $libs

# image creation
echo "IMAGE CREATION PROCESS : building grub image ..."
grub-mkrescue /usr/lib/grub/i386-pc -o bin/RoyalOS.iso RoyalOS
