#ifndef ButtonPulldown_h
#define ButtonPulldown_h

#include "Button.h"

namespace simpleButton {
    class ButtonPulldown : public Button {
        public:
            ButtonPulldown();
            ButtonPulldown(uint8_t pin);
            ~ButtonPulldown();

            void enable();

            bool read();
            void update();

            bool isEnabled();

        private:
            bool is_setup = false;
            uint8_t pin   = 255;
    };
}

#endif // ifndef ButtonPulldown_h