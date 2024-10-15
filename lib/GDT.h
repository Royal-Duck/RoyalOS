#pragma once

#include "stdint.h"

struct SegmentDescriptor{
	uint16_t lower_limit;
	uint16_t lower_base;
	uint8_t middle_base;
	uint8_t access_byte;
	uint8_t upper_limit_and_flags;
	uint8_t upper_base;
}__attribute__((packed));

void __attribute__((cdecl)) bind_GDT(struct SegmentDescriptor * GDT);

struct SegmentDescriptor GDT[5];

void define_GDT() { // We'll not implement a full GDT as we want to use paging.
	struct SegmentDescriptor null_descriptor = {0,0,0,0,0,0};
	struct SegmentDescriptor code_kernel = {0xFFFF, 0, 0, 0x9A, 0xCF, 0};
	struct SegmentDescriptor data_kernel = {0xFFFF, 0, 0, 0x92, 0xCF, 0};
	struct SegmentDescriptor code_user = {0xFFFF, 0, 0, 0xFA, 0xCF, 0};
	struct SegmentDescriptor data_user = {0xFFFF, 0, 0, 0xF2, 0xCF, 0};
	
	GDT[0] = null_descriptor;
	GDT[1] = code_kernel;
	GDT[2] = data_kernel;
	GDT[3] = code_user;
	GDT[4] = data_user;

	bind_GDT(GDT);
}
