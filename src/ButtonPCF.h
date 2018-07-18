#ifndef ButtonPCF_h
#define ButtonPCF_h

#include "Button.h"
#include <PCF8574.h>

namespace simpleButton {
    class ButtonPCF : public Button {
        public:
            ButtonPCF();
            ButtonPCF(Button* button, PCF8574* pcf, uint8_t pin);
            ~ButtonPCF();

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

#endif // ifndef ButtonPCF_h