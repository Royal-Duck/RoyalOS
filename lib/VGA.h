/*
┌──────────────────────────────────────────────────────────────────────────────┐
│                              RoyalOS VGA module                              │
├──────────────────────────────────────────────────────────────────────────────┤
│	this module is part of the RoyalOS project                                   │
│	(open source project to learn OS creation for beginers)                      │
├──────────────────────────────────────────────────────────────────────────────┤
│	USAGE:                                                                       │
│	used to write to the video memory in order to print debug.                   │
│                                                                              │
│ WARNING : THIS USAGE IS DEPRECATED, THE VGA MEMORY IS NO LONGER USED         │
└──────────────────────────────────────────────────────────────────────────────┘
*/
///
///	IMPLEMENTATION : ../src/lib/VGA.c
///


#pragma once
#include "stdint.h"
#include "better_types.h"

#define VGA_MODULE_TERM_WIDTH			80			// conventional default terminal width in characters
#define VGA_MODULE_TERM_HEIGHT		25			// conventional default terminal height in characters
#define VGA_MODULE_MEMORY_OFFSET	0xB8000	// default VGA text memory offset

void VGA_print(const char* string);
void VGA_scroll_up(void);
void VGA_reset(void);
void VGA_set_background_color(uint8_t color_16_palett);
void VGA_set_foreground_color(uint8_t color_16_palett);
void VGA_clear(uint8_t color_16_palett);
void VGA_set_cursor_position(uint8_t x, uint8_t y);
void VGA_hide_cursor(void);
void VGA_show_cursor(bool relace);
