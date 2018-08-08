#include "Event.h"

namespace simpleButton {
    void Event::run() {
        if (fnct) fnct();
    }

    uint8_t Event::getMode() {
        return MODE::DEFAULT;
    }

    uint32_t Event::getMinPushTime() {
        return 0;
    }

    uint32_t Event::getReleaseTime() {
        return 0;
    }

    uint32_t Event::getTimeSpan() {
        return 0;
    }

    uint32_t Event::getInterval() {
        return 0;
    }
}