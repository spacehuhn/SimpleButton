#include "ButtonSwitch.h"

namespace simpleButton {
    ButtonSwitch::ButtonSwitch() {}

    ButtonSwitch::ButtonSwitch(uint8_t pin) {
        ButtonSwitch::pin = pin;
        enable();
    }

    ButtonSwitch::~ButtonSwitch() {}

    void ButtonSwitch::enable() {
        if (pin != 255) {
            Button::enable();

            if (!is_setup) {
                inMode(pin, INPUT);
                is_setup = true;
            }
        }
    }

    void ButtonSwitch::update() {
        if (isEnabled() && (millis() - updateTime >= UPDATE_INTERVAL)) {
            Button::update();

            bool prevState = tmpState;
            tmpState = digitalRead(pin);

            if (prevState != tmpState) click();
        }
    }

    bool ButtonSwitch::isEnabled() {
        return Button::isEnabled() && is_setup;
    }

    bool ButtonSwitch::getState() {
        return tmpState;
    }
}