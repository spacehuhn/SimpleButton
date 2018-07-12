#include "ButtonRotaryEncoder.h"

namespace simpleButton {
    ButtonRotaryEncoder::ButtonRotaryEncoder() {}

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin) {
        ButtonRotaryEncoder::pin = pin;
        enable();
    }

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin, Button* button) {
        ButtonRotaryEncoder::buttonA = static_cast<ButtonRotaryEncoder*>(button);
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

    void ButtonRotaryEncoder::update() {
        if (buttonA && isEnabled()) {
            Button::update();

            bool curA = digitalRead(buttonA->getPin());
            bool curB = digitalRead(pin);

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
        return Button::isEnabled() && is_setup && buttonA;
    }

    uint8_t ButtonRotaryEncoder::getPin() {
        return pin;
    }
}