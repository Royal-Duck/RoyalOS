#! /bin/bash

gcc_args="-m32 -nostdlib -fno-stack-protector -fno-builtin -I lib -c"
ld_args="-I lib -m elf_i386 -T linker.ld"

# build dir cleaning
rm -rf bin/*
mkdir -p bin/src/lib

# libs compilation
libs=""
for file in src/lib/*; do
	if [ -f $file ]; then
		echo "BUILD PROCESS : compiling ${file} library ..."
		extention=${file##*.}
		error=0

		if [ "$extention" = "c" ]; then
			gcc $gcc_args $file -o "bin/${file}lib.o"
	
		elif [ "$extention" = "asm" ]; then
			nasm -f elf32 $file -o "bin/${file}lib.o"
		
		elif [ "$extention" = "cignore" ]; then
			echo -e "\033[32;1mIGNORED : ${file}\033[0m"
			error=1		
		else
			>&2 echo -e "\033[31;1mERROR : ${file}, file format not recognized !\033[0m"
			error=2
		fi
	
		if [ $error = 0 ]; then
			libs="${libs} bin/${file}lib.o"
		fi
	else
		echo "BUILD PROCESS : no library found, this might be an error"
	fi
done

# kernel compilation
echo "BUILD PROCESS : compiling the kernel ..."
gcc $gcc_args src/kernel.c -o bin/kernel.o

# boot_header compilation
echo "BUILD PROCESS : compiling the boot header file (boot.s) ..."
nasm -f elf32 src/boot.s -o bin/boot.o

# system linking
echo "LINKING PROCESS : linking the kernel ..."
ld $ld_args -o RoyalOS/boot/kernel bin/boot.o bin/kernel.o $libs

# image creation
echo "IMAGE CREATION PROCESS : building grub image ..."
grub-mkrescue /usr/lib/grub/i386-pc -o bin/RoyalOS.iso RoyalOS
