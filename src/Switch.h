#ifndef Switch_h
#define Switch_h

#include "Button.h"
#include "ButtonPCF.h"

namespace simpleButton {
    class Switch {
        public:
            Switch();
            Switch(uint8_t pin);
            Switch(PCF857x* pcf, uint8_t pin);
            ~Switch();

            void update();
            void update(bool state);

            bool getState();
            bool clicked();

        private:
            Button* button = NULL;
            bool tmpState  = false;
    };
}

#endif // ifndef Switch_h