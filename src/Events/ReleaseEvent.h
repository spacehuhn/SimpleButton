#ifndef ReleaseEvent_h
#define ReleaseEvent_h

#include "Event.h"
namespace simpleButton {
    class ReleaseEvent : public Event {
        public:
            ReleaseEvent(void(*fnct)());
            ~ReleaseEvent();

            uint8_t getMode();
    };
}

#endif // ifndef ReleaseEvent_h