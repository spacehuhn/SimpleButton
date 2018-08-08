#ifndef Event_h
#define Event_h

#include <cstddef>
#include <stdint.h>

namespace simpleButton {
    class Event {
        public:
            enum MODE { DEFAULT = 0, PUSHED = 1, RELEASED = 2, CLICKED = 3, DOUBLECLICKED = 4, HOLDING = 5 };

            virtual ~Event() = default;

            virtual void run();

            virtual uint8_t getMode();
            virtual uint32_t getMinPushTime();
            virtual uint32_t getReleaseTime();
            virtual uint32_t getTimeSpan();
            virtual uint32_t getInterval();

        protected:
            void (*fnct)() = NULL;
    };
}

#endif // ifndef Event_h