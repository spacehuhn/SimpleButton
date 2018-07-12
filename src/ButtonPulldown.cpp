#include "ButtonPulldown.h"

namespace simpleButton {
    ButtonPulldown::ButtonPulldown() {}

    ButtonPulldown::ButtonPulldown(uint8_t pin) {
        ButtonPulldown::pin = pin;
        enable();
    }

    ButtonPulldown::~ButtonPulldown() {}

    void ButtonPulldown::enable() {
        if ((pin != 255)) {
            Button::enable();

            if (!is_setup) {
                pinMode(pin, INPUT);
                is_setup = true;
            }
        }
    }

    bool ButtonPulldown::read() {
        if (isEnabled()) {
            return digitalRead(pin);
        }
        return false;
    }

    void ButtonPulldown::update() {
        if (millis() - updateTime >= UPDATE_INTERVAL) {
            Button::update();

            read() ? push() : release();
        }
    }

    bool ButtonPulldown::isEnabled() {
        return Button::isEnabled() && is_setup;
    }
}