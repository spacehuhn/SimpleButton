#ifndef HoldEvent_h
#define HoldEvent_h

#include "Event.h"
namespace simpleButton {
    class HoldEvent : public Event {
        public:
            HoldEvent(void(*fnct)(), uint32_t interval);
            ~HoldEvent();

            uint8_t getMode();
            uint32_t getInterval();

        private:
            uint32_t interval = 0;
    };
}

#endif // ifndef HoldEvent_h