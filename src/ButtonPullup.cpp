#include "ButtonPullup.h"

namespace simpleButton {
    ButtonPullup::ButtonPullup() {
        this->button_inverted = true;
        enable();
    }

    ButtonPullup::ButtonPullup(uint8_t pin) {
        this->button_pin      = pin;
        this->button_inverted = true;
        enable();
    }

    ButtonPullup::~ButtonPullup() {}

    void ButtonPullup::enable() {
        button_enabled = true;

        if ((button_pin < 255) && !button_setup) {
            pinMode(button_pin, INPUT_PULLUP);
            button_setup = true;
        }
    }
}