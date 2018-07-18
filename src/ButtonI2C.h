#ifndef ButtonI2C_h
#define ButtonI2C_h

#include "Button.h"
#include "Wire.h"

namespace simpleButton {
    class ButtonI2C : public Button {
        public:
            ButtonI2C();
            ButtonI2C(uint8_t i2cAddress, uint8_t buttonAddress);
            ButtonI2C(uint8_t i2cAddress, uint8_t buttonAddress, TwoWire* wire);
            ~ButtonI2C();

            void enable();

            bool read();

            void update();
            void update(bool state);

        private:
            TwoWire* wire;
            uint8_t buttonAddress = 0;
            uint8_t i2cAddress    = 0;
    };
}

#endif // ifndef ButtonI2C_h