#include "RotaryEncoder.h"

namespace simpleButton {
    RotaryEncoder::RotaryEncoder() {
        this->button_inverted = true;
        enable();
    }

    RotaryEncoder::RotaryEncoder(uint8_t pin) {
        this->button_pin      = pin;
        this->button_inverted = true;
        enable();
    }

    RotaryEncoder::RotaryEncoder(uint8_t pin, Button* button) {
        this->button_pin      = pin;
        this->buttonA         = button;
        this->button_inverted = true;
        enable();
    }

    RotaryEncoder::RotaryEncoder(uint8_t pin, Button* button, uint8_t button_steps) {
        this->button_pin      = pin;
        this->buttonA         = button;
        this->button_steps    = button_steps;
        this->button_inverted = true;
        enable();
    }

    RotaryEncoder::RotaryEncoder(Button* button) {
        this->buttonA         = button;
        this->button_inverted = true;
        enable();
    }

    RotaryEncoder::RotaryEncoder(Button* button, uint8_t button_steps) {
        this->buttonA         = button;
        this->button_steps    = button_steps;
        this->button_inverted = true;
        enable();
    }

    RotaryEncoder::~RotaryEncoder() {}

    void RotaryEncoder::update() {
        if (button_enabled && button_setup /*&& (millis() - updateTime >= updateInterval)*/) {
            update(read());
        }
    }

    void RotaryEncoder::enable() {
        Button::enable();
        update();
        reset();
    }

    void RotaryEncoder::reset() {
        Button::reset();

        curState  = State::STILL;
        prevState = State::STILL;

        steps = 0;
    }

    void RotaryEncoder::update(uint16_t state) {
        if (buttonA) {
            this->state = state > 0;
            update(buttonA->getState(), state);
        } else {
            this->state = state > 0;
        }
    }

    void RotaryEncoder::update(uint16_t a, uint16_t b) {
        bool curA = a > 0;
        bool curB = b > 0;

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