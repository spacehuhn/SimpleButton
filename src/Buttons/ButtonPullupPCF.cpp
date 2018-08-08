#include "ButtonPullupPCF.h"

namespace simpleButton {
    ButtonPullupPCF::ButtonPullupPCF() {
        setup(NULL, 255);
    }

    ButtonPullupPCF::ButtonPullupPCF(PCF857x* pcf, uint8_t pin) {
        setup(pcf, pin);
    }

    ButtonPullupPCF::~ButtonPullupPCF() {}

    void ButtonPullupPCF::setup(PCF857x* pcf, uint8_t pin) {
        this->pcf             = pcf;
        this->button_pin      = pin;
        this->button_inverted = true;
        enable();
    }

    void ButtonPullupPCF::enable() {
        button_enabled = true;

        if (pcf) {
            pcf->write(button_pin, 1);
            if (pcf->connected()) button_setup = true;
        }
    }
}