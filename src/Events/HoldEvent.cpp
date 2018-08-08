#include "HoldEvent.h"

namespace simpleButton {
    HoldEvent::HoldEvent(void (*fnct)(), uint32_t timeSpan) {
        this->fnct     = fnct;
        this->timeSpan = timeSpan;
    }

    HoldEvent::~HoldEvent() {}

    uint8_t HoldEvent::getMode() {
        return MODE::HOLDING;
    }

    uint32_t HoldEvent::getTimeSpan() {
        return timeSpan;
    }
}