#include "RotaryEncoderPCF.h"

namespace simpleButton {
    RotaryEncoderPCF::RotaryEncoderPCF() {
        this->clockwise     = new ButtonPCF();
        this->anticlockwise = new ButtonPCF();
        this->button        = new ButtonPullupPCF();
    }

    RotaryEncoderPCF::RotaryEncoderPCF(PCF857x* pcf, uint8_t channelA, uint8_t channelB) {
        this->clockwise     = new ButtonPCF(pcf, channelA);
        this->anticlockwise = new ButtonPCF(pcf, channelB);
        this->button        = new ButtonPullupPCF();

        prevA = clockwise->read();
        prevB = anticlockwise->read();
    }

    RotaryEncoderPCF::RotaryEncoderPCF(PCF857x* pcf, uint8_t channelA, uint8_t channelB, uint8_t button) {
        this->clockwise     = new ButtonPCF(pcf, channelA);
        this->anticlockwise = new ButtonPCF(pcf, channelB);
        this->button        = new ButtonPullupPCF(pcf, button);

        prevA = clockwise->read();
        prevB = anticlockwise->read();
    }

    RotaryEncoderPCF::~RotaryEncoderPCF() {}
}