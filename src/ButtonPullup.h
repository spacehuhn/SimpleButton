#ifndef ButtonPullup_h
#define ButtonPullup_h

#include "Button.h"

namespace simpleButton {
    class ButtonPullup : public Button {
        public:
            ButtonPullup();
            ButtonPullup(uint8_t pin);
            ~ButtonPullup();

            void enable();
    };
}

#endif // ifndef ButtonPullup_h