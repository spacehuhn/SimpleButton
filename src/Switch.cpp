#include "Switch.h"

namespace simpleButton {
    Switch::Switch() {
        button = new Button();
    }

    Switch::Switch(uint8_t pin) {
        button   = new Button(pin);
        tmpState = button->read();
    }

    Switch::Switch(PCF857x* pcf, uint8_t pin) {
        button   = new ButtonPCF(pcf, pin);
        tmpState = button->read();
    }

    Switch::~Switch() {}

    void Switch::update() {
        update(button->read());
    }

    void Switch::update(bool state) {
        bool prevState = tmpState;

        tmpState = state > 0;

        if (prevState != tmpState) button->click();
    }

    bool Switch::getState() {
        return tmpState;
    }

    bool Switch::clicked() {
        return button->clicked();
    }
}