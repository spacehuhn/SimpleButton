#include "PCF8575.h"

PCF8575::PCF8575(uint8_t address) {
    PCF8575::wire    = &Wire;
    PCF8575::address = address;
}

PCF8575::PCF8575(uint8_t address, TwoWire* wire) {
    PCF8575::wire    = wire;
    PCF8575::address = address;
}

PCF8575::~PCF8575() {}

int PCF8575::read() {
    wire->beginTransmission(address);
    wire->requestFrom(address, (uint8_t)2);

    data = 0;

    if (wire->available() >= 2) {
        data  = i2cRead();
        data |= i2cRead() << 8;
    }

    wire->endTransmission();

    return data;
}

int PCF8575::read(uint8_t pin) {
    data = read();

    return (data & (1 << pin)) > 0;
}

void PCF8575::write(int value) {
    wire->beginTransmission(address);

    pinModeMask = value;
    data        = pinModeMask;

    i2cWrite((uint8_t)data);
    i2cWrite((uint8_t)(data >> 8));

    wire->endTransmission();
}

void PCF8575::write(uint8_t pin, int value) {
    uint8_t val = value & 1;

    if (val) pinModeMask |= val << pin;
    else pinModeMask &= ~(1 << pin);

    write(pinModeMask);
}

void PCF8575::toggle() {
    pinModeMask = ~pinModeMask;
    write(pinModeMask);
}

void PCF8575::toggle(uint8_t pin) {
    pinModeMask ^= 1 << pin;

    write(pinModeMask);
}

void PCF8575::shiftRight(uint8_t n) {
    pinModeMask >>= n;
    write(pinModeMask);
}

void PCF8575::shiftLeft(uint8_t n) {
    pinModeMask <<= n;
    write(pinModeMask);
}

void PCF8575::rotateLeft(uint8_t n) {
    rotateRight(16 - (n & 15));
}

void PCF8575::rotateRight(uint8_t n) {
    uint8_t r = n & 15;

    pinModeMask = (pinModeMask >> r) | (pinModeMask << (16 - r));

    write(pinModeMask);
}