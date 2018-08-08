#include "ReleaseEvent.h"

namespace simpleButton {
    ReleaseEvent::ReleaseEvent(void (*fnct)()) {
        this->fnct = fnct;
    }

    ReleaseEvent::~ReleaseEvent() {}

    uint8_t ReleaseEvent::getMode() {
        return MODE::RELEASED;
    }
}