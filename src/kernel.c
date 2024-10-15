//#include "../lib/OS_debug.h"
#include "VGA.h"
#include "GDT.h"

void kmain(void); // called when starting

void kmain(void){
	define_GDT();
	VGA_hide_cursor();
	VGA_show_cursor(true);
	VGA_clear(9);
	VGA_set_background_color(1);
	VGA_set_cursor_position(1, 1);
	VGA_print("Hello, world!\n");
	VGA_set_foreground_color(5);
	VGA_print("test");
}
