#include "AnalogStick.h"

namespace simpleButton {
    AnalogStick::AnalogStick() {
        this->button = new Button();
        this->up     = new ButtonAnalog(0, 55);
        this->down   = new ButtonAnalog(200, 255);
        this->left   = new ButtonAnalog(0, 55);
        this->right  = new ButtonAnalog(200, 255);

        this->setup = true;
    }

    AnalogStick::AnalogStick(uint8_t xPin, uint8_t yPin, uint8_t buttonPin) {
        this->xPin      = xPin;
        this->yPin      = yPin;
        this->buttonPin = buttonPin;

        pinMode(xPin, INPUT);
        pinMode(yPin, INPUT);
        pinMode(buttonPin, INPUT);

        this->button = new ButtonPullup(buttonPin);
        this->up     = new ButtonAnalog(yPin, 0, 55);
        this->down   = new ButtonAnalog(yPin, 200, 255);
        this->left   = new ButtonAnalog(xPin, 0, 55);
        this->right  = new ButtonAnalog(xPin, 200, 255);

        this->setup = true;
    }

    AnalogStick::~AnalogStick() {}

    void AnalogStick::update() {
        if (setup && (millis() - updateTime >= updateInterval)) {
            updateInterval = millis();

            button->update();
            up->update();
            down->update();
            left->update();
            right->update();

            this->xValue = left->getState();
            this->yValue = up->getState();
        }
    }

    void AnalogStick::update(uint8_t xValue, uint8_t yValue, bool buttonPress) {
        if (setup && (millis() - updateTime >= updateInterval)) {
            updateInterval = millis();

            this->xValue = xValue;
            this->yValue = yValue;

            button->update(buttonPress);
            up->update(yValue);
            down->update(yValue);
            left->update(xValue);
            right->update(xValue);
        }
    }

    uint8_t AnalogStick::getX() {
        return xValue;
    }

    uint8_t AnalogStick::getY() {
        return yValue;
    }
}