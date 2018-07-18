#include "ButtonRotaryEncoder.h"

namespace simpleButton {
    ButtonRotaryEncoder::ButtonRotaryEncoder() {
        this->button_inverted = true;
        enable();
    }

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin) {
        this->button_pin      = pin;
        this->button_inverted = true;
        enable();
    }

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin, Button* button) {
        this->button_pin      = pin;
        this->buttonA         = button;
        this->button_inverted = true;
        enable();
    }

    ButtonRotaryEncoder::ButtonRotaryEncoder(uint8_t pin, Button* button, uint8_t button_steps) {
        this->button_pin      = pin;
        this->buttonA         = button;
        this->button_steps    = button_steps;
        this->button_inverted = true;
        enable();
    }

    ButtonRotaryEncoder::~ButtonRotaryEncoder() {}

    void ButtonRotaryEncoder::update() {
        if (button_enabled && button_setup /*&& (millis() - updateTime >= UPDATE_INTERVAL)*/) {
            update(read());
        }
    }

    void ButtonRotaryEncoder::update(bool state) {
        if (buttonA) {
            this->state = state;
            update(buttonA->getState(), state);
        } else {
            this->state = state;
        }
    }

    void ButtonRotaryEncoder::update(bool curA, bool curB) {
        updateTime = millis();

        if (curState == State::STILL) {
            if ((curA != prevA) && (curB == prevB)) {
                prevA    = curA;
                curState = State::CLOCKWISE;
            } else if ((curA == prevA) && (curB != prevB)) {
                prevB    = curB;
                curState = State::ANTICLOCKWISE;
            }
        } else if ((curState != State::STILL) && (curA == curB)) {
            prevA = curA;
            prevB = curB;

            if (curState == prevState) steps++;
            else steps = 1;

            if (steps >= button_steps) {
                if (curState == State::CLOCKWISE) {
                    click();
                } else /*if (curState == State::ANTICLOCKWISE) */ {
                    buttonA->click();
                }

                steps = 0;
            }

            prevState = curState;
            curState  = State::STILL;
        }
    }
}