#include "ButtonRotaryEncoder.h"

namespace simpleButton {
    ButtonRotaryEncoder::ButtonRotaryEncoder() {}

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin) {
        ButtonRotaryEncoder::pin = pin;
        enable();
    }

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin, Button* button) {
        ButtonRotaryEncoder::buttonA = button;
        ButtonRotaryEncoder::pin     = pin;
        enable();
    }

    ButtonRotaryEncoder::~ButtonRotaryEncoder() {}

    void ButtonRotaryEncoder::enable() {
        if ((pin != 255)) {
            Button::enable();

            if (!is_setup) {
                pinMode(pin, INPUT_PULLUP);
                is_setup = true;
            }
        }
    }

    bool ButtonRotaryEncoder::read() {
        if (isEnabled()) {
            return digitalRead(pin);
        }
        return false;
    }

    void ButtonRotaryEncoder::update() {
        if (buttonA && (millis() - updateTime >= UPDATE_INTERVAL)) {
            Button::update();

            bool curA = buttonA->read();
            bool curB = read();

            if ((prevA == LOW) && (curA == HIGH)) {
                if (curB == LOW) {
                    click();
                } else {
                    buttonA->click();
                }
            }

            prevA = curA;
        }
    }

    bool ButtonRotaryEncoder::isEnabled() {
        return Button::isEnabled() && is_setup;
    }
}