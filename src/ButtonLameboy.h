#ifndef ButtonLameboy_h
#define ButtonLameboy_h

#include "Button.h"
#include "Wire.h"

namespace simpleButton {
    class ButtonLameboy : public Button {
        public:
            ButtonLameboy();
            ButtonLameboy(uint8_t i2cAddress, uint8_t buttonAddress);
            ButtonLameboy(uint8_t i2cAddress, uint8_t buttonAddress, TwoWire* wire);
            ~ButtonLameboy();

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

#endif // ifndef ButtonLameboy_h