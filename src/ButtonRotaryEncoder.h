#ifndef ButtonRotaryEncoder_h
#define ButtonRotaryEncoder_h

#include "Button.h"

namespace simpleButton {
    class ButtonRotaryEncoder : public Button {
        public:
            uint32_t UPDATE_INTERVAL       = 0;
            uint32_t DEFAULT_MIN_PUSH_TIME = 40;
            uint32_t DEFAULT_TIME_SPAN     = 650;
            uint32_t DEFAULT_HOLD_INTERVAL = 250;

            ButtonRotaryEncoder();
            ButtonRotaryEncoder(uint8_t pin);
            ButtonRotaryEncoder(uint8_t pin, Button* button);
            ButtonRotaryEncoder(uint8_t pin, Button* button, uint8_t button_steps);

            ~ButtonRotaryEncoder();

            void update();
            void update(bool state);
            void update(bool curA, bool curB);

        private:
            Button* buttonA = NULL;

            bool prevA = false;
            bool prevB = false;

            enum State { STILL = 0, CLOCKWISE = 1, ANTICLOCKWISE = 2 };
            State curState  = State::STILL;
            State prevState = State::STILL;

            uint8_t button_steps = 1;
            uint8_t steps        = 0;
    };
}

#endif // ifndef ButtonRotaryEncoder_h