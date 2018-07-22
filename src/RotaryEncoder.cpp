#include "RotaryEncoder.h"

namespace simpleButton {
    RotaryEncoder::RotaryEncoder() {
        this->clockwise     = new Button();
        this->anticlockwise = new Button();
        this->button        = new ButtonPullup();
    }

    RotaryEncoder::RotaryEncoder(uint8_t channelA, uint8_t channelB) {
        this->clockwise     = new Button(channelA);
        this->anticlockwise = new Button(channelB);
        this->button        = new ButtonPullup();

        prevA = clockwise->read();
        prevB = anticlockwise->read();
    }

    RotaryEncoder::RotaryEncoder(uint8_t channelA, uint8_t channelB, uint8_t button) {
        this->clockwise     = new Button(channelA);
        this->anticlockwise = new Button(channelB);
        this->button        = new ButtonPullup(button);

        prevA = clockwise->read();
        prevB = anticlockwise->read();
    }

    RotaryEncoder::~RotaryEncoder() {}

    void RotaryEncoder::update() {
        update(clockwise->read(), anticlockwise->read(), button->read());
    }

    void RotaryEncoder::update(bool stateA, bool stateB, bool buttonState) {
        button->update(buttonState);

        if (curState == State::STILL) {
            if ((stateA != prevA) && (stateB == prevB)) {
                prevA    = stateA;
                curState = State::ANTICLOCKWISE;
            } else if ((stateA == prevA) && (stateB != prevB)) {
                prevB    = stateB;
                curState = State::CLOCKWISE;
            }
        } else if ((curState != State::STILL) && (stateA == stateB)) {
            prevA = stateA;
            prevB = stateB;

            if (curState == prevState) steps++;
            else steps = 1;

            if (steps >= button_steps) {
                if (curState == State::CLOCKWISE) {
                    clockwise->click();
                    pos++;
                } else if (curState == State::ANTICLOCKWISE)  {
                    anticlockwise->click();
                    pos--;
                }

                steps = 0;
            }

            prevState = curState;
            curState  = State::STILL;
        }
    }

    void RotaryEncoder::reset() {
        button->reset();
        clockwise->reset();
        anticlockwise->reset();

        curState  = State::STILL;
        prevState = State::STILL;

        steps = 0;
    }

    int8_t RotaryEncoder::getPos() {
        return pos;
    }

    void RotaryEncoder::setPos(int8_t pos) {
        this->pos = pos;
    }

    void RotaryEncoder::setSteps(uint8_t steps) {
        this->button_steps = steps;
    }
}