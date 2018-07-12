#include "ButtonI2C.h"

namespace simpleButton {
    ButtonI2C::ButtonI2C() {}

    ButtonI2C::ButtonI2C(uint8_t i2cAddress, uint8_t buttonAddress) {
        ButtonI2C::i2cAddress    = i2cAddress;
        ButtonI2C::buttonAddress = buttonAddress;
        Button::enable();
    }

    ButtonI2C::~ButtonI2C() {}

    bool ButtonI2C::read() {
        if (isEnabled()) {
            Wire.requestFrom((int)i2cAddress, 1);
            byte data = Wire.read();
            return (~data & buttonAddress) > 0;
        }
        return false;
    }

    void ButtonI2C::update() {
        if (millis() - updateTime >= UPDATE_INTERVAL) {
            Button::update();

            read() ? push() : release();
        }
    }
}