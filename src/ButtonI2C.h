#ifndef ButtonI2C_h
#define ButtonI2C_h

#include "Button.h"
#include "Wire.h"

namespace simpleButton {
    class ButtonI2C : public Button {
        public:
            ButtonI2C();
            ButtonI2C(uint8_t i2cAddress, uint8_t buttonAddress);
            ~ButtonPullup();

            void update();

        private:
            uint8_t buttonAddress = 0;
            uint8_t i2cAddress    = 0;
    };
}

#endif // ifndef ButtonI2C_h