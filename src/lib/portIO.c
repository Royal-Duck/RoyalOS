#include "portIO.h"
#include "stdint.h"

void __attribute__((cdecl)) asm_IO_port_out(uint16_t port, uint8_t byte); 					// writes "byte" to serial port "port"
void __attribute__((cdecl)) asm_IO_port_in(uint16_t port, uint8_t * return_adress);	// returns the value read from "port"

uint8_t IO_port_in(uint16_t port){
	uint8_t value;
	asm_IO_port_in(port, &value);
	return value;
}

void IO_port_out(uint16_t port, uint8_t byte){
	asm_IO_port_out(port, byte);
}
