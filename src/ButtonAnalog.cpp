#include "ButtonAnalog.h"

namespace simpleButton {
    ButtonAnalog::ButtonAnalog() {
        enable();
    }

    ButtonAnalog::ButtonAnalog(uint8_t pin, uint16_t minValue, uint16_t maxValue) {
        this->button_pin = pin;
        this->minValue   = minValue;
        this->maxValue   = maxValue;
        enable();
    }

    ButtonAnalog::ButtonAnalog(uint8_t pin, uint16_t minValue, uint16_t maxValue, bool inverted) {
        this->button_pin      = pin;
        this->minValue        = minValue;
        this->maxValue        = maxValue;
        this->button_inverted = inverted;
        enable();
    }

    ButtonAnalog::~ButtonAnalog() {}

    uint16_t ButtonAnalog::read() {
        uint16_t currentState = 0;

        if (button_enabled && button_setup) {
            currentState = analogRead(button_pin);

            if (button_inverted) currentState = 1024 - currentState;
        }

        value = currentState;

        return currentState;
    }

    void ButtonAnalog::update() {
        if (button_enabled && button_setup && (millis() - updateTime >= updateInterval)) {
            update(read());
        }
    }

    void ButtonAnalog::update(uint16_t state) {
        updateTime = millis();

        if ((state >= minValue) && (state <= maxValue)) push();
        else release();
    }

    uint16_t ButtonAnalog::getState() {
        return value;
    }
}