#ifndef SimpleButton_PushEvent_h
#define SimpleButton_PushEvent_h

#include "Event.h"

namespace simpleButton {
    class PushEvent : public Event {
        public:
            PushEvent(void(*fnct)());
            ~PushEvent();

            uint8_t getMode();
    };
}

#endif // ifndef SimpleButton_PushEvent_h