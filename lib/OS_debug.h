/*
┌──────────────────────────────────────────────────────────────────────────────┐
│                             RoyalOS debug module                             │
├──────────────────────────────────────────────────────────────────────────────┤
│	this module is part of the RoyalOS project                                   │
│	(open source project to learn OS creation for beginers)                      │
├──────────────────────────────────────────────────────────────────────────────┤
│	USAGE:                                                                       │
│	used to send debug messages in various ways such as writing to ports.        │
└──────────────────────────────────────────────────────────────────────────────┘
*/

#pragma once

#include "stdint.h"
#include "better_types.h"
#include "./portIO.h"

void OS_debug_E9P_putc(char character);									// putc for E9 port, refer to the implementation file for more info
void OS_debug_E9P_puts(const char* str);								// puts for E9 port, refer to the implementation file for more info
void OS_debug_E9P_putn(uint64_t number, bool is_signed);// number debug for E9 port, refer to the implementation file for more info
