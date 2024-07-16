OUTPUT_FORMAT(elf32-i386) /* 32 bits linking */
ENTRY(start)							/* defines that the first part of the binary is the start symbol defined in src/boot.s */
SECTIONS {
	. = 0x100000;						/* not to erase BIOS */
	.text : {*(.text)}
	.data : {*(.data)}
	.bss  : {*(.bss)}
}
