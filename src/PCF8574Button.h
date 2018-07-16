#ifndef PCF8574Button_h
#define PCF8574Button_h

#include "Button.h"
#include <PCF8574.h>

namespace simpleButton {
    class PCF8574Button : public Button {
        public:
            uint32_t UPDATE_INTERVAL       = 25;
            uint32_t DEFAULT_MIN_PUSH_TIME = 40;
            uint32_t DEFAULT_TIME_SPAN     = 650;
            uint32_t DEFAULT_HOLD_INTERVAL = 250;

            PCF8574Button();
            PCF8574Button(Button* button, PCF8574* pcf, uint8_t pin);
            ~PCF8574Button();

            void enable();
            void disable();

            void push();
            void release();

            void click();
            void click(uint32_t time);

            bool read();
            void update();
            void update(bool state);

            bool isEnabled();
            bool isSetup();

            bool getState();
            int getClicks();
            int getPushTime();

            bool pushed();
            bool released();
            bool clicked();
            bool clicked(uint32_t minPushTime);
            bool doubleClicked();
            bool doubleClicked(uint32_t minPushTime);
            bool doubleClicked(uint32_t minPushTime, uint32_t timeSpan);
            bool holded();
            bool holded(uint32_t interval);

        private:
            Button* button = NULL;
            PCF8574* pcf   = NULL;
    };
}

#endif // ifndef PCF8574Button_h