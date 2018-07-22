#ifndef ButtonPCF_h
#define ButtonPCF_h

#include "Button.h"
#include "PCF8574.h"
#include "PCF8575.h"

namespace simpleButton {
    class ButtonPCF : public Button {
        public:
            ButtonPCF();
            ButtonPCF(Button* button, PCF857x* pcf, uint8_t pin);
            ~ButtonPCF();

            void enable();
            void disable();
            void reset();

            void push();
            void release();

            void click();
            void click(uint32_t time);

            int read();
            void update();
            void update(int state);

            bool isEnabled();
            bool isSetup();

            bool getState();
            int getClicks();
            int getPushTime();

            bool pushed();
            bool released();
            bool clicked();
            bool clicked(uint32_t minPushTime);
            bool clicked(uint32_t minPushTime, uint32_t minReleaseTime);
            bool doubleClicked();
            bool doubleClicked(uint32_t minPushTime);
            bool doubleClicked(uint32_t minPushTime, uint32_t timeSpan);
            bool doubleClicked(uint32_t minPushTime, uint32_t minReleaseTime, uint32_t timeSpan);
            bool holding();
            bool holding(uint32_t interval);

        private:
            Button* button = NULL;
            PCF857x* pcf   = NULL;
    };
}

#endif // ifndef ButtonPCF_h