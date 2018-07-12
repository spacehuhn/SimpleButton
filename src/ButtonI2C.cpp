#include "ButtonI2C.h"

namespace simpleButton {
    ButtonI2C::ButtonI2C() {}

    ButtonI2C::ButtonI2C(uint8_t i2cAddress, uint8_t buttonAddress) {
        ButtonI2C::i2cAddress    = i2cAddress;
        ButtonI2C::buttonAddress = buttonAddress;
        Button::enable();
    }

    ButtonI2C::~ButtonI2C() {}

    void ButtonI2C::update() {
        if (isEnabled() && (millis() - updateTime >= UPDATE_INTERVAL)) {
            Button::update();

            Wire.requestFrom((int)i2cAddress, 1);
            byte data  = Wire.read();
            bool state = (~data & buttonAddress) > 0;

            if (state) push();
            else release();
        }
    }
}