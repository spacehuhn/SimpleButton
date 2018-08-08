#ifndef ClickEvent_h
#define ClickEvent_h

#include "Event.h"
namespace simpleButton {
    class ClickEvent : public Event {
        public:
            ClickEvent(void(*fnct)(), uint32_t minPushTime, uint32_t releaseTime);
            ~ClickEvent();

            uint8_t getMode();
            uint32_t getMinPushTime();
            uint32_t getReleaseTime();

        private:
            uint32_t minPushTime = 0;
            uint32_t releaseTime = 0;
    };
}

#endif // ifndef ClickEvent_h