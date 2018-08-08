#include "DoubleclickEvent.h"

namespace simpleButton {
    DoubleclickEvent::DoubleclickEvent(void (*fnct)(), uint32_t minPushTime, uint32_t releaseTime, uint32_t timeSpan) {
        this->fnct        = fnct;
        this->minPushTime = minPushTime;
        this->releaseTime = releaseTime;
        this->timeSpan    = timeSpan;
    }

    DoubleclickEvent::~DoubleclickEvent() {}

    uint8_t DoubleclickEvent::getMode() {
        return MODE::DOUBLECLICKED;
    }

    uint32_t DoubleclickEvent::getMinPushTime() {
        return minPushTime;
    }

    uint32_t DoubleclickEvent::getReleaseTime() {
        return releaseTime;
    }

    uint32_t DoubleclickEvent::getTimeSpan() {
        return timeSpan;
    }
}