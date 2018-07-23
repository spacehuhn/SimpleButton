#ifndef ButtonPullupPCF_h
#define ButtonPullupPCF_h

#include "ButtonPCF.h"

namespace simpleButton {
    class ButtonPullupPCF : public ButtonPCF {
        public:
            ButtonPullupPCF();
            ButtonPullupPCF(PCF857x* pcf, uint8_t pin);
            ~ButtonPullupPCF();

            void enable();
    };
}

#endif // ifndef ButtonPullupPCF_h