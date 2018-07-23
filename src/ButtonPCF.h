#ifndef ButtonPCF_h
#define ButtonPCF_h

#include "Button.h"
#include "PCF8574.h"
#include "PCF8575.h"

namespace simpleButton {
    class ButtonPCF : public Button {
        public:
            ButtonPCF();
            ButtonPCF(PCF857x* pcf, uint8_t pin);
            ButtonPCF(PCF857x* pcf, uint8_t pin, bool inverted);
            ~ButtonPCF();

            void enable();

            int read();
            void update();
            void update(int state);

        protected:
            PCF857x* pcf = NULL;
    };
}

#endif // ifndef ButtonPCF_h