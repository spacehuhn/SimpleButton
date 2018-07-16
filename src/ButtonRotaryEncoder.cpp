#include "ButtonRotaryEncoder.h"

namespace simpleButton {
    ButtonRotaryEncoder::ButtonRotaryEncoder() {
        enable();
    }

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin) {
        this->button_pin = pin;
        enable();
    }

    ButtonRotaryEncoder::ButtonRotaryEncoder(Button* button) {
        this->buttonA = button;
        enable();
    }

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin, Button* button) {
        this->button_pin = pin;
        this->buttonA    = button;
        enable();
    }

    ButtonRotaryEncoder::~ButtonRotaryEncoder() {}

    void ButtonRotaryEncoder::update() {
        if (button_enabled && button_setup && (millis() - updateTime >= UPDATE_INTERVAL)) {
            update(read());
        }
    }

    void ButtonRotaryEncoder::update(bool state) {
        if (buttonA) {
            update(buttonA->getState(), state);
        } else {
            state ? release() : push();
        }
    }

    void ButtonRotaryEncoder::update(bool stateA, bool stateB) {
        updateTime = millis();

        bool curA = stateA;
        bool curB = stateB;

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