#include "HoldEvent.h"

namespace simpleButton {
    HoldEvent::HoldEvent(void (*fnct)(), uint32_t interval) {
        this->fnct     = fnct;
        this->interval = interval;
    }

    HoldEvent::~HoldEvent() {
        if (next) {
            delete next;
            next = NULL;
        }
    }

    uint8_t HoldEvent::getMode() {
        return MODE::HOLDING;
    }

    uint32_t HoldEvent::getInterval() {
        return interval;
    }
}