#ifndef ButtonAnalog_h
#define ButtonAnalog_h

#include "Button.h"


namespace simpleButton {
    class ButtonAnalog : public Button {
        public:
            ButtonAnalog();
            ButtonAnalog(uint8_t pin, uint16_t minValue, uint16_t maxValue);
            ButtonAnalog(uint8_t pin, uint16_t minValue, uint16_t maxValue, bool inverted);
            ~ButtonAnalog();

            uint16_t read();

            void update();
            void update(uint16_t state);

            uint16_t getState();

        private:
            uint16_t minValue = 0;
            uint16_t maxValue = 1024;
            uint16_t value    = 0;
    };
}
#endif // ifndef ButtonAnalog_h