#ifndef Switch_h
#define Switch_h

#include "Button.h"

namespace simpleButton {
    class Switch : public Button {
        public:
            Switch();
            Switch(uint8_t pin);
            ~Switch();

            void enable();

            void update();
            void update(bool state);

            bool getState();

        private:
            bool tmpState = false;
    };
}

#endif // ifndef Switch_h