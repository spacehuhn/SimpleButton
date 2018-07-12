#ifndef Button_h
#define Button_h

#include "Arduino.h"

namespace simpleButton {
    class Button {
        public:
            virtual ~Button() = default;

            virtual void enable();
            virtual void disable();
            virtual void push();
            virtual void release();
            virtual void click();
            virtual void click(uint32_t time);

            virtual bool read() = 0;
            virtual void update();

            virtual bool isEnabled();
            virtual bool getState();
            virtual int getClicks();
            virtual int getPushTime();

            virtual bool pushed();
            virtual bool released();

            virtual bool clicked();
            virtual bool clicked(uint32_t minPushTime);
            virtual bool doubleClicked();
            virtual bool doubleClicked(uint32_t minPushTime);
            virtual bool doubleClicked(uint32_t minPushTime, uint32_t timeSpan);
            virtual bool holded();
            virtual bool holded(uint32_t interval);

            virtual void setUpdateInterval(uint32_t time);
            virtual void setMinPushTime(uint32_t minPushTime);
            virtual void setTimeSpan(uint32_t timeSpan);
            virtual void setHoldInterval(uint32_t interval);

        protected:
            bool button_enabled = false;
            bool state          = false;
            bool pushedFlag     = false;
            bool releasedFlag   = false;
            bool holdFlag       = false;

            uint16_t clicks          = 0;
            uint32_t prevPushTime    = 0;
            uint32_t prevReleaseTime = 0;
            uint32_t pushTime        = 0;
            uint32_t holdTime        = 0;
            uint32_t updateTime      = 0;

            uint32_t UPDATE_INTERVAL       = 25;
            uint32_t DEFAULT_MIN_PUSH_TIME = 40;
            uint32_t DEFAULT_TIME_SPAN     = 650;
            uint32_t DEFAULT_HOLD_INTERVAL = 250;
    };
}

#endif // ifndef Button_h