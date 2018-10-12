#include "PushEvent.h"

namespace simplebutton {
    PushEvent::PushEvent(void (*fnct)()) {
        this->fnct = fnct;
    }

    PushEvent::~PushEvent() {
        if (next) {
            delete next;
            next = NULL;
        }
    }

    uint8_t PushEvent::getMode() {
        return MODE::PUSHED;
    }
}