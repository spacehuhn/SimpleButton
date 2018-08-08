#ifndef PCF8575_h
#define PCF8575_h

#include "PCF857x.h"

namespace simpleButton {
    class PCF8575 : public PCF857x {
        public:
            PCF8575(uint8_t address);
            PCF8575(uint8_t address, TwoWire* wire);

            ~PCF8575();

            int read();
            int read(uint8_t pin);

            void write(int value);
            void write(uint8_t pin, int value);

            void toggle();
            void toggle(uint8_t pin);

            void shiftLeft(uint8_t n  = 1);
            void shiftRight(uint8_t n = 1);

            void rotateLeft(uint8_t n  = 1);
            void rotateRight(uint8_t n = 1);

        private:
            uint16_t data;
            uint16_t pinModeMask;
    };
}
#endif // ifndef PCF8575_h