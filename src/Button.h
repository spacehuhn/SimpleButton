#ifndef Button_h
#define Button_h

#include "Arduino.h"
#include "globals.h"

namespace simpleButton {
    class Button {
        public:
            virtual Button()  = default;
            virtual ~Button() = default;

            void enable();
            void disable();
            void push();
            void release();
            void click(uint32_t time);

            void update();

            bool isEnabled();
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
            bool button_enabled      = false;
            bool state               = false;
            bool pushedFlag          = false;
            bool releasedFlag        = false;
            bool holdFlag            = false;
            uint16_t clicks          = 0;
            uint32_t prevPushTime    = 0;
            uint32_t prevReleaseTime = 0;
            uint32_t pushTime        = 0;
            uint32_t holdTime        = 0;

        protected:
            uint32_t updateTime = 0;
    };
}

#endif // ifndef Button_h