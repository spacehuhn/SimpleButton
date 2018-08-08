#ifndef PushEvent_h
#define PushEvent_h

#include "Event.h"
namespace simpleButton {
    class PushEvent : public Event {
        public:
            PushEvent(void(*fnct)());
            ~PushEvent();

            uint8_t getMode();
    };
}

#endif // ifndef PushEvent_h