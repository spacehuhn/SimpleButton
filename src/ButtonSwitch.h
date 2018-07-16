#ifndef ButtonSwitch_h
#define ButtonSwitch_h

#include "Button.h"

namespace simpleButton {
    class ButtonSwitch : public Button {
        public:
            ButtonSwitch();
            ButtonSwitch(uint8_t pin);
            ~ButtonSwitch();

            void update();
            void update(bool state);

            bool getState();

        private:
            bool tmpState = false;
    };
}

#endif // ifndef ButtonSwitch_h