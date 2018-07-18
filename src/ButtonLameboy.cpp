#include "ButtonLameboy.h"

namespace simpleButton {
    ButtonLameboy::ButtonLameboy() {
        this->defaultMinPushTime = 20;
        this->defaultTimeSpan    = 450;

        enable();
    }

    ButtonLameboy::ButtonLameboy(uint8_t i2cAddress, uint8_t buttonAddress) {
        this->defaultMinPushTime = 20;
        this->defaultTimeSpan    = 450;
        this->i2cAddress         = i2cAddress;
        this->buttonAddress      = buttonAddress;
        this->wire               = &Wire;
        enable();
    }

    ButtonLameboy::ButtonLameboy(uint8_t i2cAddress, uint8_t buttonAddress, TwoWire* wire) {
        this->defaultMinPushTime = 20;
        this->defaultTimeSpan    = 450;
        this->i2cAddress         = i2cAddress;
        this->buttonAddress      = buttonAddress;
        this->wire               = wire;
        enable();
    }

    ButtonLameboy::~ButtonLameboy() {}

    void ButtonLameboy::enable() {
        Button::enable();

        if (i2cAddress && buttonAddress && wire) button_setup = true;
    }

    bool ButtonLameboy::read() {
        bool res = false;

        if (button_enabled && button_setup) {
            wire->beginTransmission(i2cAddress);

            wire->requestFrom((int)i2cAddress, 1);
            uint8_t data = wire->read();
            res = (~data & buttonAddress) == 0;

            wire->endTransmission();
        }

        return res;
    }

    void ButtonLameboy::update() {
        if (button_enabled && button_setup && (millis() - updateTime >= updateInterval)) {
            update(read());
        }
    }

    void ButtonLameboy::update(bool state) {
        updateTime = millis();
        state ? release() : push();
    }
}