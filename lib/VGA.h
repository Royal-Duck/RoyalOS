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

#pragma once
#include "stdint.h"

#define VGA_MODULE_TERM_WIDTH		80	// conventional default terminal width in characters
#define VGA_MODULE_TERM_HEIGHT	25	// conventional default terminal height in characters

// the functions under are name explicit, however there are not implemented, refer to the implementation
void VGA_print(const char* string);
void VGA_scroll_up(void);
void VGA_new_line(void);
void VGA_reset(void);
void VGA_set_bg_color(uint8_t color);
void VGA_set_fg_color(uint8_t color);
