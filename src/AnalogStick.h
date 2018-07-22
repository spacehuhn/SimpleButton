#ifndef AnalogStick_h
#define AnalogStick_h

#include "ButtonPullup.h"
#include "ButtonAnalog.h"

namespace simpleButton {
    class AnalogStick {
        public:
            Button* button      = NULL;
            ButtonAnalog* up    = NULL;
            ButtonAnalog* down  = NULL;
            ButtonAnalog* left  = NULL;
            ButtonAnalog* right = NULL;

            uint32_t updateInterval = 5;

            AnalogStick();
            AnalogStick(uint8_t xPin, uint8_t yPin, uint8_t buttonPin);
            ~AnalogStick();

            void update();
            void update(uint8_t xValue, uint8_t yValue, bool buttonPress);

            uint8_t getX();
            uint8_t getY();

        private:
            bool setup = false;

            uint8_t xValue = 0;
            uint8_t yValue = 0;

            uint8_t xPin      = 0;
            uint8_t yPin      = 0;
            uint8_t buttonPin = 0;

            uint32_t updateTime = 0;
    };
}

#endif // ifndef AnalogStick_h