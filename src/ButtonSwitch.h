#ifndef ButtonSwitch_h
#define ButtonSwitch_h

#include "Button.h"

namespace simpleButton {
    class ButtonSwitch : public Button {
        public:
            ButtonSwitch();
            ButtonSwitch(uint8_t pin);
            ~ButtonSwitch();

            void enable();

            bool read();
            void update();

            bool isEnabled();
            bool getState();

        private:
            bool is_setup = false;
            bool tmpState = false;
            uint8_t pin   = 255;
    };
}

#endif // ifndef ButtonSwitch_h