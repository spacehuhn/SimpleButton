#ifndef RotaryEncoderPCF_h
#define RotaryEncoderPCF_h

#include "Button.h"
#include "RotaryEncoder.h"
#include "PCF8574.h"
#include "PCF8575.h"
#include "ButtonPCF.h"
#include "ButtonPullupPCF.h"

namespace simpleButton {
    class RotaryEncoderPCF : public RotaryEncoder {
        public:
            RotaryEncoderPCF();
            RotaryEncoderPCF(PCF857x* pcf, uint8_t channelA, uint8_t channelB);
            RotaryEncoderPCF(PCF857x* pcf, uint8_t channelA, uint8_t channelB, uint8_t button);
            ~RotaryEncoderPCF();
    };
}

#endif // ifndef RotaryEncoderPCF_h