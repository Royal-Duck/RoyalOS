#pragma once

#include "./stdint.h"

void IO_port_out(uint16_t port, uint8_t byte);
uint8_t IO_port_in(uint16_t port);
