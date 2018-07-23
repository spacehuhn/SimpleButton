#include "PCF857x.h"

namespace simpleButton {
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