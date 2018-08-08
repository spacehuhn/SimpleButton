#ifndef PushedEvent_h
#define PushedEvent_h

#include "Event.h"
namespace simpleButton {
    class PushedEvent : public Event {
        public:
            PushedEvent(void(*fnct)());
            ~PushedEvent();

            uint8_t getMode();
    };
}

#endif // ifndef PushedEvent_h