#ifndef ButtonPullup_h
#define ButtonPullup_h

#include "Button.h"

namespace simpleButton {
    class ButtonPullup : public Button {
        public:
            uint32_t UPDATE_INTERVAL       = 25;
            uint32_t DEFAULT_MIN_PUSH_TIME = 40;
            uint32_t DEFAULT_TIME_SPAN     = 650;
            uint32_t DEFAULT_HOLD_INTERVAL = 250;

            ButtonPullup();
            ButtonPullup(uint8_t pin);
            ~ButtonPullup();

            void enable();
    };
}

#endif // ifndef ButtonPullup_h