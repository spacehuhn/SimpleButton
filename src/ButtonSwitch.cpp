#include "ButtonSwitch.h"

namespace simpleButton {
    ButtonSwitch::ButtonSwitch() {
        enable();
    }

    ButtonSwitch::ButtonSwitch(uint8_t pin) {
        this->button_pin = pin;
        enable();
    }

    ButtonSwitch::~ButtonSwitch() {}

    void ButtonSwitch::update() {
        if (button_enabled && button_setup && (millis() - updateTime >= UPDATE_INTERVAL)) update(read());
    }

    void ButtonSwitch::update(bool state) {
        updateTime = millis();

        bool prevState = tmpState;
        tmpState = state;

        if (prevState != tmpState) click();
    }

    bool ButtonSwitch::getState() {
        return tmpState;
    }
}