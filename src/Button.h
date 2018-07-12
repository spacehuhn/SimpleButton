#ifndef Button_h
#define Button_h

#include "Arduino.h"

namespace simpleButton {
    class Button {
        public:
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

            void setUpdateInterval(uint32_t time);
            void setMinPushTime(uint32_t minPushTime);
            void setTimeSpan(uint32_t timeSpan);
            void setHoldInterval(uint32_t interval);

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

            uint32_t UPDATE_INTERVAL       = 25;
            uint32_t DEFAULT_MIN_PUSH_TIME = 40;
            uint32_t DEFAULT_TIME_SPAN     = 800;
            uint32_t DEFAULT_HOLD_INTERVAL = 600;
    };
}

#endif // ifndef Button_h