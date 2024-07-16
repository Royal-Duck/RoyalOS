/*
┌──────────────────────────────────────────────────────────────────────────────┐
│                             RoyalOS math module                              │
├──────────────────────────────────────────────────────────────────────────────┤
│	this module is part of the RoyalOS project                                   │
│	(open source project to learn OS creation for beginers)                      │
├──────────────────────────────────────────────────────────────────────────────┤
│	USAGE:                                                                       │
│	used to replace libgcc and math.h from std.                                  │
└──────────────────────────────────────────────────────────────────────────────┘
*/

#pragma once

#include "stdint.h"

// gives the remainder of the euclidian division "number / moulus"
// replaces __umoddi3 from the libgcc that we cannot use
uint64_t umod64(uint64_t number, uint64_t modulus){
	uint64_t reminder = number;
	while (reminder >= modulus){
		reminder -= modulus;
	}
	return reminder;
}

// gives the quotient of the euclidian division "numerator / denominator"
// replaces __divdi3 from the libgcc that we cannot use
int64_t div64(int64_t numerator, int64_t denominator){
	int64_t quotient = 0;
	while (numerator >= denominator){
		numerator -= denominator;
		quotient ++;
	}
	return quotient;
}
