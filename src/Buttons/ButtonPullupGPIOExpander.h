#ifndef ButtonPullupGPIOExpander_h
#define ButtonPullupGPIOExpander_h

#include "ButtonGPIOExpander.h"

namespace simpleButton {
    class ButtonPullupGPIOExpander : public ButtonGPIOExpander {
        public:
            ButtonPullupGPIOExpander();
            ButtonPullupGPIOExpander(GPIOExpander* pcf, uint8_t pin);

            ~ButtonPullupGPIOExpander();

            void setup(GPIOExpander* pcf, uint8_t pin);

            void enable();
    };
}

#endif // ifndef ButtonPullupGPIOExpander_h