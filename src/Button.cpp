#include "SimpleButton.h"

namespace simpleButton {
    Button::Button() {
        enable();
    }

    Button::Button(uint8_t pin) {
        this->button_pin = pin;
        enable();
    }

    Button::Button(uint8_t pin, bool inverted) {
        this->button_pin      = pin;
        this->button_inverted = inverted;
        enable();
    }

    Button::~Button() {}

    void Button::enable() {
        button_enabled = true;

        if ((button_pin < 255) && !button_setup) {
            pinMode(button_pin, INPUT);
            button_setup = true;
        }
    }

    void Button::disable() {
        button_enabled = false;
    }

    void Button::push() {
        if (!state) {
            state = true;

            prevPushTime    = pushTime;
            prevReleaseTime = millis();
            pushedFlag      = true;

            pushTime = millis();
            holdTime = millis();
            holdFlag = false;
        }
    }

    void Button::release() {
        if (state) {
            state        = false;
            releasedFlag = true;
        }
    }

    void Button::click() {
        click(DEFAULT_MIN_PUSH_TIME);
    }

    void Button::click(uint32_t time) {
        push();
        pushTime = millis() - time;
        release();
    }

    bool Button::read() {
        bool currentState = false;

        if (button_enabled && button_setup) {
            currentState = digitalRead(button_pin);

            if (button_inverted) currentState = !currentState;
        }

        return currentState;
    }

    void Button::update() {
        if (button_enabled && button_setup && (millis() - updateTime >= UPDATE_INTERVAL)) {
            update(read());
        }
    }

    void Button::update(bool state) {
        updateTime = millis();
        state ? release() : push();
    }

    bool Button::isInverted() {
        return button_inverted;
    }

    bool Button::isEnabled() {
        return button_enabled;
    }

    bool Button::isSetup() {
        return button_setup;
    }

    bool Button::getState() {
        return state;
    }

    int Button::getClicks() {
        return (int)clicks;
    }

    int Button::getPushTime() {
        return (int)(millis() - pushTime);
    }

    bool Button::pushed() {
        if (pushedFlag) {
            pushedFlag = false;
            return true;
        }
        return false;
    }

    bool Button::released() {
        if (releasedFlag) {
            releasedFlag = false;
            return true;
        }
        return false;
    }

    bool Button::clicked() {
        return clicked(DEFAULT_MIN_PUSH_TIME);
    }

    bool Button::clicked(uint32_t minPushTime) {
        bool isReleased = released();
        bool notHolding = !holdFlag;
        bool minTime    = millis() - pushTime >= minPushTime;

        if (isReleased && notHolding && minTime) {
            clicks++;
            return true;
        }

        return false;
    }

    bool Button::doubleClicked() {
        return doubleClicked(DEFAULT_MIN_PUSH_TIME);
    }

    bool Button::doubleClicked(uint32_t minPushTime) {
        return doubleClicked(minPushTime, DEFAULT_TIME_SPAN);
    }

    bool Button::doubleClicked(uint32_t minPushTime, uint32_t timeSpan) {
        bool wasClicked     = clicked(minPushTime);
        bool wasPrevClicked = prevReleaseTime - prevPushTime >= minPushTime;
        bool inTimeSpan     = millis() - prevPushTime <= timeSpan;

        bool res = wasClicked && wasPrevClicked && inTimeSpan;

        if (!res && wasClicked) releasedFlag = true;

        if (res) pushTime = 0;

        return res;
    }

    bool Button::holded() {
        return holded(DEFAULT_HOLD_INTERVAL);
    }

    bool Button::holded(uint32_t interval) {
        if (getState() && (millis() - holdTime >= interval)) {
            holdTime = millis();
            holdFlag = true;
            return true;
        }
        return false;
    }
}