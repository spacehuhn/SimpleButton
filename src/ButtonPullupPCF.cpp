#include "ButtonPullupPCF.h"

namespace simpleButton {
    ButtonPullupPCF::ButtonPullupPCF() {
        enable();
    }

    ButtonPullupPCF::ButtonPullupPCF(PCF857x* pcf, uint8_t pin) {
        this->pcf             = pcf;
        this->button_pin      = pin;
        this->button_inverted = true;
        enable();
    }

    ButtonPullupPCF::~ButtonPullupPCF() {}

    void ButtonPullupPCF::enable() {
        button_enabled = true;

        if (pcf && (button_pin < 16)) {
            pcf->write(button_pin, HIGH);
            button_setup = true;
        }
    }
}