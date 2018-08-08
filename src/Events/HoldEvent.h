#ifndef HoldEvent_h
#define HoldEvent_h

#include "Event.h"
namespace simpleButton {
    class HoldEvent : public Event {
        public:
            HoldEvent(void(*fnct)(), uint32_t timeSpan);
            ~HoldEvent();

            uint8_t getMode();
            uint32_t getTimeSpan();

        private:
            uint32_t timeSpan = 0;
    };
}

#endif // ifndef HoldEvent_h