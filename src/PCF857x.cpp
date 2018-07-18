#include "PCF857x.h"

uint8_t PCF857x::i2cRead() {
    return wire->read();
}

void PCF857x::i2cWrite(uint8_t data) {
    wire->write(data);
}