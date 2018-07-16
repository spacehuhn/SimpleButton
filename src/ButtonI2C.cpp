#include "ButtonI2C.h"

namespace simpleButton {
    ButtonI2C::ButtonI2C() {
        enable();
    }

    ButtonI2C::ButtonI2C(uint8_t i2cAddress, uint8_t buttonAddress) {
        this->i2cAddress    = i2cAddress;
        this->buttonAddress = buttonAddress;
        this->wire          = &Wire;
        enable();
    }

    ButtonI2C::ButtonI2C(uint8_t i2cAddress, uint8_t buttonAddress, TwoWire* wire) {
        this->i2cAddress    = i2cAddress;
        this->buttonAddress = buttonAddress;
        this->wire          = wire;
        enable();
    }

    ButtonI2C::~ButtonI2C() {}

    void ButtonI2C::enable() {
        Button::enable();

        if (i2cAddress && buttonAddress && wire) button_setup = true;
    }

    bool ButtonI2C::read() {
        bool res = false;

        if (button_enabled && button_setup) {
            wire->beginTransmission(i2cAddress);

            wire->requestFrom((int)i2cAddress, 1);
            uint8_t data = wire->read();
            res = (~data & buttonAddress) > 0;

            wire->endTransmission();
        }

        return res;
    }

    void ButtonI2C::update() {
        if (button_enabled && button_setup && (millis() - updateTime >= UPDATE_INTERVAL)) {
            update(read());
        }
    }

    void ButtonI2C::update(bool state) {
        updateTime = millis();
        state ? release() : push();
    }
}