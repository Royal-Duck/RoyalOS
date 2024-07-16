/*
┌──────────────────────────────────────────────────────────────────────────────┐
│                        RoyalOS better types module                           │
├──────────────────────────────────────────────────────────────────────────────┤
│	this module is part of the RoyalOS project                                   │
│	(open source project to learn OS creation for beginers)                      │
├──────────────────────────────────────────────────────────────────────────────┤
│	USAGE:                                                                       │
│	used to alias int types to their "rust style" naming.                        │
└──────────────────────────────────────────────────────────────────────────────┘
*/

#pragma once

#define true 		1
#define false 	0

typedef unsigned char				u8;
typedef char								i8;
typedef unsigned int				u16;
typedef int									i16;
typedef unsigned long				u32;
typedef long								i32;
typedef unsigned long long	u64;
typedef long long						i64;
typedef u8									bool;
