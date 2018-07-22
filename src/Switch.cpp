#include "Switch.h"

namespace simpleButton {
    Switch::Switch() {
        enable();
    }

    Switch::Switch(uint8_t pin) {
        this->button_pin = pin;
        enable();
    }

    Switch::~Switch() {}

    void Switch::enable() {
        Button::enable();
        tmpState = read();
    }

    void Switch::update() {
        if (button_enabled && button_setup && (millis() - updateTime >= updateInterval)) update(read());
    }

    void Switch::update(uint16_t state) {
        updateTime = millis();

        bool prevState = tmpState;
        tmpState = state > 0;

        if (prevState != tmpState) click();
    }

    uint16_t Switch::getState() {
        return tmpState;
    }
}