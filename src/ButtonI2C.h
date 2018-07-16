#ifndef ButtonI2C_h
#define ButtonI2C_h

#include "Button.h"
#include "Wire.h"

namespace simpleButton {
    class ButtonI2C : public Button {
        public:
            uint32_t UPDATE_INTERVAL       = 25;
            uint32_t DEFAULT_MIN_PUSH_TIME = 40;
            uint32_t DEFAULT_TIME_SPAN     = 650;
            uint32_t DEFAULT_HOLD_INTERVAL = 250;

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