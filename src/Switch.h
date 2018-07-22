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
            void update(uint16_t state);

            uint16_t getState();

        private:
            bool tmpState = false;
    };
}

#endif // ifndef Switch_h