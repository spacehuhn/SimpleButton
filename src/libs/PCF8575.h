#ifndef PCF8575_h
#define PCF8575_h

#include "GPIOExpander.h"

namespace simpleButton {
    class PCF8575 : public GPIOExpander {
        public:
            PCF8575(uint8_t address);
            PCF8575(uint8_t address, TwoWire* wire);

            ~PCF8575();

            int read();
            int read(uint8_t pin);

            void write(int value);
            void write(uint8_t pin, bool value);

            void toggle();
            void toggle(uint8_t pin);

        private:
            uint16_t data;
            uint16_t pinModeMask;
    };
}
#endif // ifndef PCF8575_h