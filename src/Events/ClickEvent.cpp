#include "ClickEvent.h"

namespace simpleButton {
    ClickEvent::ClickEvent(void (*fnct)(), uint32_t minPushTime, uint32_t releaseTime) {
        this->fnct        = fnct;
        this->minPushTime = minPushTime;
        this->releaseTime = releaseTime;
    }

    ClickEvent::~ClickEvent() {}

    uint8_t ClickEvent::getMode() {
        return MODE::CLICKED;
    }

    uint32_t ClickEvent::getMinPushTime() {
        return minPushTime;
    }

    uint32_t ClickEvent::getReleaseTime() {
        return releaseTime;
    }
}