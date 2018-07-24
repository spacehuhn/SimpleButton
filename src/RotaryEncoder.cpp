#include "RotaryEncoder.h"

namespace simpleButton {
    RotaryEncoder::RotaryEncoder() {
        setButtons(NULL, NULL, NULL);
    }

    RotaryEncoder::RotaryEncoder(uint8_t channelA, uint8_t channelB, uint8_t button) {
        setup(channelA, channelB, button);
    }

    RotaryEncoder::RotaryEncoder(PCF857x* pcf, uint8_t channelA, uint8_t channelB, uint8_t button) {
        setup(pcf, channelA, channelB, button);
    }

    RotaryEncoder::RotaryEncoder(Button* clockwise, Button* anticlockwise, Button* button) {
        setup(clockwise, anticlockwise, button);
    }

    RotaryEncoder::~RotaryEncoder() {
        if (this->clockwise) delete this->clockwise;
        if (this->anticlockwise) delete this->anticlockwise;
        if (this->button) delete this->button;
    }

    void RotaryEncoder::setup(uint8_t channelA, uint8_t channelB, uint8_t button) {
        this->clockwise     = new ButtonPullup(channelA);
        this->anticlockwise = new ButtonPullup(channelB);
        this->button        = new ButtonPullup(button);

        prevA = clockwise->read();
        prevB = anticlockwise->read();
    }

    void RotaryEncoder::setup(PCF857x* pcf, uint8_t channelA, uint8_t channelB, uint8_t button) {
        this->clockwise     = new ButtonPullupPCF(pcf, channelA);
        this->anticlockwise = new ButtonPullupPCF(pcf, channelB);
        this->button        = new ButtonPullupPCF(pcf, button);

        prevA = clockwise->read();
        prevB = anticlockwise->read();
    }

    void RotaryEncoder::setup(Button* clockwise, Button* anticlockwise, Button* button) {
        setButtons(clockwise, anticlockwise, button);

        prevA = clockwise->read();
        prevB = anticlockwise->read();
    }

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

    int32_t RotaryEncoder::getPos() {
        return pos;
    }

    void RotaryEncoder::setButtons(Button* clockwise, Button* anticlockwise, Button* button) {
        if (this->clockwise) delete this->clockwise;
        if (this->anticlockwise) delete this->anticlockwise;
        if (this->button) delete this->button;

        this->clockwise     = clockwise ? clockwise : new Button();
        this->anticlockwise = anticlockwise ? anticlockwise : new Button();
        this->button        = button ? button : new Button();
    }

    void RotaryEncoder::setPos(int32_t pos) {
        this->pos = pos;
    }

    void RotaryEncoder::setSteps(uint8_t steps) {
        this->button_steps = steps;
    }
}