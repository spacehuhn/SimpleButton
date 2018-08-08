#include "DoubleclickEvent.h"

namespace simpleButton {
    DoubleclickEvent::DoubleclickEvent(void (*fnct)(), uint32_t minPushTime, uint32_t minReleaseTime,
                                       uint32_t timeSpan) {
        this->fnct           = fnct;
        this->minPushTime    = minPushTime;
        this->minReleaseTime = minReleaseTime;
        this->timeSpan       = timeSpan;
    }

    DoubleclickEvent::~DoubleclickEvent() {
        if (next) {
            delete next;
            next = NULL;
        }
    }

    uint8_t DoubleclickEvent::getMode() {
        return MODE::DOUBLECLICKED;
    }

    uint32_t DoubleclickEvent::getMinPushTime() {
        return minPushTime;
    }

    uint32_t DoubleclickEvent::getMinReleaseTime() {
        return minReleaseTime;
    }

    uint32_t DoubleclickEvent::getTimeSpan() {
        return timeSpan;
    }
}