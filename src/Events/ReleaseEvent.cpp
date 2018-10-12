#include "ReleaseEvent.h"

namespace simplebutton {
    ReleaseEvent::ReleaseEvent(void (*fnct)()) {
        this->fnct = fnct;
    }

    ReleaseEvent::~ReleaseEvent() {
        if (next) {
            delete next;
            next = NULL;
        }
    }

    uint8_t ReleaseEvent::getMode() {
        return MODE::RELEASED;
    }
}