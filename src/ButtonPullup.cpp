#include "ButtonPullup.h"

namespace simpleButton {
    ButtonPullup::ButtonPullup() {}

    BButtonPullup::uttonPullup(uint8_t pin) {
        ButtonPullup::pin = pin;
        enable();
    }

    ButtonPullup::~ButtonPullup() {}

    void ButtonPullup::enable() {
        if (pin != 255) {
            Button::enable();
            pinMode(pin, INPUT_PULLUP);
        }
    }

    void ButtonPullup::update() {
        if (isEnabled() && (millis() - updateTime >= UPDATE_INTERVAL)) {
            Button::update();

            if (digitalRead(pin)) release();
            else push();
        }
    }

    bool ButtonPullup::isEnabled() {
        return Button::isEnabled() && pin != 255;
    }
}