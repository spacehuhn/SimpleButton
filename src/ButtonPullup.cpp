#include "ButtonPullup.h"

namespace simpleButton {
    ButtonPullup::ButtonPullup() {}

    ButtonPullup::ButtonPullup(uint8_t pin) {
        ButtonPullup::pin = pin;
        enable();
    }

    ButtonPullup::~ButtonPullup() {}

    void ButtonPullup::enable() {
        if ((pin != 255)) {
            Button::enable();

            if (!is_setup) {
                pinMode(pin, INPUT_PULLUP);
                is_setup = true;
            }
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
        return Button::isEnabled() && is_setup;
    }
}