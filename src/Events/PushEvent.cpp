#include "PushEvent.h"

namespace simpleButton {
    PushEvent::PushEvent(void (*fnct)()) {
        this->fnct = fnct;
    }

    PushEvent::~PushEvent() {}

    uint8_t PushEvent::getMode() {
        return MODE::PUSHED;
    }
}