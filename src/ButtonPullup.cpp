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

    bool ButtonPullup::read() {
        if (isEnabled()) {
            return digitalRead(pin);
        }
        return false;
    }

    void ButtonPullup::update() {
        if (millis() - updateTime >= UPDATE_INTERVAL) {
            Button::update();

            read() ? release() : push();
        }
    }

    bool ButtonPullup::isEnabled() {
        return Button::isEnabled() && is_setup;
    }
}