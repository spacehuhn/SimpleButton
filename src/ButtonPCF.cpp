#include "ButtonPCF.h"

namespace simpleButton {
    ButtonPCF::ButtonPCF() {
        enable();
    }

    ButtonPCF::ButtonPCF(PCF857x* pcf, uint8_t pin) {
        this->pcf        = pcf;
        this->button_pin = pin;
        enable();
    }

    ButtonPCF::ButtonPCF(PCF857x* pcf, uint8_t pin, bool inverted) {
        this->pcf             = pcf;
        this->button_pin      = pin;
        this->button_inverted = inverted;
        enable();
    }

    ButtonPCF::~ButtonPCF() {}

    void ButtonPCF::enable() {
        button_enabled = true;

        if (pcf && (button_pin < 16)) {
            button_setup = true;
        }
    }

    int ButtonPCF::read() {
        bool currentState = false;

        if (button_enabled && button_setup) {
            currentState = pcf->read(button_pin) > 0;

            if (button_inverted) currentState = !currentState;
        }

        return (int)currentState;
    }

    void ButtonPCF::update() {
        if (button_enabled && button_setup) {
            update(read());
        }
    }

    void ButtonPCF::update(int state) {
        Button::update(state);
    }
}