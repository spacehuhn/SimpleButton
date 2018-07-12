#ifndef ButtonRotaryEncoder_h
#define ButtonRotaryEncoder_h

#include "Button.h"

namespace simpleButton {
    class ButtonRotaryEncoder : public Button {
        public:
            ButtonRotaryEncoder();
            ButtonRotaryEncoder(uint8_t pin);
            ButtonRotaryEncoder(uint8_t pin, Button* button);
            ~ButtonRotaryEncoder();

            void enable();

            bool read();
            void update();

            bool isEnabled();

        protected:
            uint32_t UPDATE_INTERVAL = 1;

        private:
            bool is_setup   = false;
            uint8_t pin     = 255;
            Button* buttonA = NULL;
            bool prevA      = false;
    };
}

#endif // ifndef ButtonRotaryEncoder_h