#include "VGA.h"
#include "portIO.h"
#include "stdint.h"

uint8_t cursor_x = 0;
uint8_t cursor_y = 0;
uint8_t foreground_color = 15;
uint8_t background_color = 0;
uint8_t * offset = (uint8_t *)VGA_MODULE_MEMORY_OFFSET;

void place_cursor(void) {
	uint16_t position = cursor_y * VGA_MODULE_TERM_WIDTH + cursor_x;
	IO_port_out(0x3D4, 0x0F);
	IO_port_out(0x3D5, (uint8_t) (position & 0xFF));
	IO_port_out(0x3D4, 0x0E);
	IO_port_out(0x3D5, (uint8_t) ((position >> 8) & 0xFF));
}

void VGA_print(const char *string){
	if (cursor_x >= VGA_MODULE_TERM_WIDTH) {
		cursor_x = 0;
		cursor_y ++;
	}
	if (cursor_y >= VGA_MODULE_TERM_HEIGHT) {
		VGA_scroll_up();
	}
	while (*string){
		if (*string == '\n'){
			cursor_y ++;
			cursor_x = 0;
			string ++;
			continue;
		}
		offset[2*(cursor_y * VGA_MODULE_TERM_WIDTH)+2*cursor_x] = *string;
		offset[2*(cursor_y * VGA_MODULE_TERM_WIDTH)+2*cursor_x + 1] = ((background_color*16)|foreground_color);
		cursor_x ++;
		string ++;
	}
	place_cursor();
}

void VGA_clear(uint8_t color){
	for (uint8_t y = 0; y < VGA_MODULE_TERM_HEIGHT; y ++){
		for (uint8_t x = 0; x < VGA_MODULE_TERM_WIDTH; x ++){
			offset[2*(y*VGA_MODULE_TERM_WIDTH)+2*x] = ' ';
			offset[2*(y*VGA_MODULE_TERM_WIDTH)+2*x + 1] = ((color*16)|foreground_color);
		}
	}
	place_cursor();
}

void VGA_reset(){
	cursor_x = 0;
	cursor_y = 0;
	foreground_color = 15;
	background_color = 0;
	VGA_clear(background_color);
}

void VGA_set_background_color(uint8_t color){
	background_color = color;
}

void VGA_set_foreground_color(uint8_t color){
	foreground_color = color;
}

void VGA_scroll_up(){
	for (uint8_t y = 0; y < VGA_MODULE_TERM_HEIGHT-1; y ++){
		for (uint8_t x = 0; x < VGA_MODULE_TERM_WIDTH; x ++){
			offset[2*(y*VGA_MODULE_TERM_WIDTH)+2*x] = offset[2*((y+1)*VGA_MODULE_TERM_WIDTH)+2*x];
			offset[2*(y*VGA_MODULE_TERM_WIDTH)+2*x + 1] = offset[2*((y+1)*VGA_MODULE_TERM_WIDTH)+2*x + 1];
		}
	}
	place_cursor();
}

void VGA_set_cursor_position(uint8_t x, uint8_t y){
	cursor_x = x;
	cursor_y = y;
}

void VGA_hide_cursor(){
	IO_port_out(0x3D4, 0x0A);
	IO_port_out(0x3D5, 0x20);
}

void VGA_show_cursor(bool replace){
	uint8_t start_cursor = replace ? 0 : 14;
	IO_port_out(0x3D4, 0x0A);
	IO_port_out(0x3D5, (IO_port_in(0x3D5) & 0xC0) | start_cursor);
	IO_port_out(0x3D4, 0x0B);
	IO_port_out(0x3D5, (IO_port_in(0x3D5) & 0xE0) | 15);
}
