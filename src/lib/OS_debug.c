/*
┌──────────────────────────────────────────────────────────────────────────────┐
│                            RoyalOS debug module                              │
├──────────────────────────────────────────────────────────────────────────────┤
│	this module is part of the RoyalOS project                                   │
│	(open source project to learn OS creation for beginers)                      │
├──────────────────────────────────────────────────────────────────────────────┤
│	USAGE:                                                                       │
│	used to debug internal values of the OS.                                     │
└──────────────────────────────────────────────────────────────────────────────┘
*/

#include "OS_debug.h"
#include "math.h"

// TIP : THE E9 PORT IS USED BY BOCHS AND QEMU TO DEBUG STUFF
// IN QEMU, THE -debugcon OPTION IS NEEDED ALONG WITH THE OUT FILE 

// sends the given character to the E9 port
void OS_debug_E9P_putc(char character){
	IO_port_out(0xE9, character);
}

// sends the given string to the E9 port
void OS_debug_E9P_puts(const char* str){
	while (*str) {
		OS_debug_E9P_putc(*str);
		str ++;
	}
}

// sends the given number to the E9 port
// TODO : fix the wired error that makes the kernel stop after the function
void OS_debug_E9P_putn(uint64_t number, bool is_signed){
	bool negative = false;
	char* buffer;
	uint64_t num = 0;

	if (is_signed){
		if ((int64_t)number < 0){
			negative = true;
		}
		num = (uint64_t)(number * -1);
	}
	else {
		num = number;
	}
	
	int8_t counter = 0;
	while (num > 0){
		buffer[counter] = umod64(num, 10) + 48; // ascii code of the least significant digit
		num = div64(num, 10);										// goes to the next digit to the left
		counter ++;
	}
	if (negative){
		buffer[counter] = '-';									// adds the "-" sign in front of the string
	}
	while (counter >= 0){
		OS_debug_E9P_putc(buffer[counter]);			// prints the string in the reverse order
		counter --;
	}
}
