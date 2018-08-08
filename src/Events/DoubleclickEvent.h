#ifndef DoubleclickEvent_h
#define DoubleclickEvent_h

#include "Event.h"
namespace simpleButton {
    class DoubleclickEvent : public Event {
        public:
            DoubleclickEvent(void(*fnct)(), uint32_t minPushTime, uint32_t releaseTime, uint32_t timeSpan);
            ~DoubleclickEvent();

            uint8_t getMode();
            uint32_t getMinPushTime();
            uint32_t getReleaseTime();
            uint32_t getTimeSpan();

        private:
            uint32_t minPushTime = 0;
            uint32_t releaseTime = 0;
            uint32_t timeSpan    = 0;
    };
}

#endif // ifndef DoubleclickEvent_h