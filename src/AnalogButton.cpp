#include "AnalogButton.h"

#include "Arduino.h" // pinMode, analogRead, ...

AnalogButton::AnalogButton(int pin, int minValue, int maxValue) : Button(pin, BUTTON_DEFAULT), minValue(minValue), maxValue(maxValue), value(0) {}

// Getter
int AnalogButton::read() const {
    int currentState = 0;

    if (enabled()) {
        currentState = analogRead(config.pin);
    }

    return currentState;
}

int AnalogButton::getMin() const {
    return minValue;
}

int AnalogButton::getMax() const {
    return maxValue;
}

int AnalogButton::getValue() const {
    return value;
}

// Setter
void AnalogButton::update() {
    if (millis() - state.update_time >= config.update_interval) {
        if (enabled()) update(read());
    }
}

void AnalogButton::update(int newState) {
    this->value = newState; /*
                               Serial.print(newState);
                               Serial.print(" = ");
                               Serial.print((newState >= minValue) && (newState <= maxValue));
                               Serial.print("[");
                               Serial.print(minValue);
                               Serial.print(",");
                               Serial.print(maxValue);
                               Serial.println("]");*/
    Button::update((newState >= minValue) && (newState <= maxValue));
}

void AnalogButton::setMin(int minValue) {
    this->minValue = minValue;
}

void AnalogButton::setMax(int maxValue) {
    this->maxValue = maxValue;
}