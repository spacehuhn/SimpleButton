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

    Switch::Switch(Button* button) {
        setButton(button);
        tmpState = button->read();
    }

    Switch::~Switch() {
        if (this->button) delete this->button;
    }

    void Switch::update() {
        update(button->read());
    }

    void Switch::update(bool state) {
        bool prevState = tmpState;

        tmpState = state > 0;

        if (prevState != tmpState) button->click();
    }

    void Switch::setButton(Button* button) {
        if (this->button) delete this->button;
        this->button = button ? button ? new Button();
    }

    bool Switch::getState() {
        return tmpState;
    }

    bool Switch::clicked() {
        return button->clicked();
    }
}