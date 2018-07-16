#ifndef ButtonRotaryEncoder_h
#define ButtonRotaryEncoder_h

#include "Button.h"

namespace simpleButton {
    class ButtonRotaryEncoder : public Button {
        public:
            uint32_t UPDATE_INTERVAL       = 5;
            uint32_t DEFAULT_MIN_PUSH_TIME = 40;
            uint32_t DEFAULT_TIME_SPAN     = 650;
            uint32_t DEFAULT_HOLD_INTERVAL = 250;

            ButtonRotaryEncoder();
            ButtonRotaryEncoder(uint8_t pin);
            ButtonRotaryEncoder(Button* button);
            ButtonRotaryEncoder(uint8_t pin, Button* button);
            ~ButtonRotaryEncoder();

            void update();
            void update(bool state);
            void update(bool stateA, bool stateB);

        private:
            Button* buttonA = NULL;
            bool prevA      = false;
    };
}

#endif // ifndef ButtonRotaryEncoder_h