#include "ButtonAnalog.h"

namespace simpleButton {
    ButtonAnalog::ButtonAnalog() {
        enable();
    }

    ButtonAnalog::ButtonAnalog(uint8_t pin) {
        this->button_pin = pin;
        enable();
    }

    ButtonAnalog::ButtonAnalog(uint16_t minValue, uint16_t maxValue) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        enable();
    }

    ButtonAnalog::ButtonAnalog(uint8_t pin, uint16_t minValue, uint16_t maxValue) {
        this->button_pin = pin;
        this->minValue   = minValue;
        this->maxValue   = maxValue;
        enable();
    }

    ButtonAnalog::~ButtonAnalog() {}

    int ButtonAnalog::read() {
        int currentState = 0;

        if (button_enabled && button_setup) {
            currentState = analogRead(button_pin);
        }

        return currentState;
    }

    void ButtonAnalog::update() {
        if (button_enabled && button_setup && (millis() - updateTime >= updateInterval)) {
            update(read());
        }
    }

    void ButtonAnalog::update(int state) {
        uint16_t newState = state;

        updateTime = millis();

        value = newState;

        if ((newState >= minValue) && (newState <= maxValue)) push();
        else release();
    }

    void ButtonAnalog::setMin(uint16_t minValue) {
        this->minValue = minValue;
    }

    void ButtonAnalog::setMax(uint16_t maxValue) {
        this->maxValue = maxValue;
    }

    void ButtonAnalog::setBounds(uint16_t minValue, uint16_t maxValue) {
        setMin(minValue);
        setMax(maxValue);
    }

    uint16_t ButtonAnalog::getValue() {
        return value;
    }
}