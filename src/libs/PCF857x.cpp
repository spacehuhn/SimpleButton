#include "PCF857x.h"

namespace simpleButton {
    void PCF857x::setup(uint8_t address) {
        this->wire    = &Wire;
        this->address = address;
        write(0);
    }

    void PCF857x::setup(uint8_t address, TwoWire* wire) {
        this->wire    = wire;
        this->address = address;
        write(0);
    }

    bool PCF857x::connected() {
        return error == 0;
    }

    String PCF857x::getError() {
        String msg;

        switch (error) {
        case 0:
            msg += "OK";
            break;

        case 1:
            msg += String(F("Data too long to fit in transmit buffer"));
            break;

        case 2:
            msg += String(F("Received NACK on transmit of address"));
            break;

        case 3:
            msg += String(F("Received NACK on transmit of data"));

        case 4:
            msg += String(F("Unknown transmission error"));
            break;

        case 5:
            msg += String(F("Pin error"));
            break;

        case 6:
            msg += String(F("I2C error"));
            break;
        }

        return msg;
    }
}