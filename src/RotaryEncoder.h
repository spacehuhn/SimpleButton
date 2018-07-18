#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include "Button.h"

namespace simpleButton {
    class RotaryEncoder : public Button {
        public:
            uint32_t updateInterval = 0;

            RotaryEncoder();
            RotaryEncoder(uint8_t pin);
            RotaryEncoder(uint8_t pin, Button* button);
            RotaryEncoder(uint8_t pin, Button* button, uint8_t button_steps);
            RotaryEncoder(Button* button);
            RotaryEncoder(Button* button, uint8_t button_steps);

            ~RotaryEncoder();

            void enable();
            void reset();

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

#endif // ifndef RotaryEncoder_h