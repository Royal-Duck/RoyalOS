;┌──────────────────────────────────────────────────────────────────────────────┐
;│                          RoyalOS BOOTLOADER info                             │
;├──────────────────────────────────────────────────────────────────────────────┤
;│	this module is part of the RoyalOS project                                  │
;│	(open source project to learn OS creation for beginers)                     │
;├──────────────────────────────────────────────────────────────────────────────┤
;│	this file sets up all the data for grub to find the kernel and allows us to │
;│	launch it                                                                   │
;└──────────────────────────────────────────────────────────────────────────────┘

bits 32

section .text
	align 4												; aligning for 32 bits protected mode
	dd 0x1BADB002									; magic number : tells grub that this file is an OS entry
	dd 0x00000000									; grub flags (we have none)
	dd -(0x1BADB002 + 0x00000000)	; ensures that no data was corrupted
	
global start		; makes the start symbol accessible form everywher in the kernel's bin
extern kmain		; tells the linker to find a function called kmain (the kernel entry point | kernel.c)

start:
	cli										; disables interupts
	mov esp, stack_space	; initialize the stack
	call kmain						; jumps to the kernel
	hlt										; halt the CPU if kmain returned

crash_guard:			; infinite loop to halt in case the CPU turns back on
	cli
	hlt
	jmp crash_guard

section .bss
resb 8192			; reserves 8192 bytes for the stack
stack_space:	; because the stack grows downward, we need to place the symbol after the resb
