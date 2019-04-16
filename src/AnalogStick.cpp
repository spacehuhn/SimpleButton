#include "AnalogStick.h"

AnalogStick::AnalogStick(int xPin, int yPin, int selectPin) {
    up    = AnalogButton(yPin, 0, 256);
    down  = AnalogButton(yPin, 768, 1024);
    left  = AnalogButton(xPin, 0, 256);
    right = AnalogButton(xPin, 768, 1024);

    select = Button(selectPin);
}

AnalogStick::AnalogStick(AnalogButton up, AnalogButton down, AnalogButton left, AnalogButton right, Button select) {
    up    = up;
    down  = down;
    left  = left;
    right = right;

    select = select;
}

// Getter
int AnalogStick::readX() const {
    return left.read();
}

int AnalogStick::readY() const {
    return up.read();
}

int AnalogStick::readSelect() const {
    return select.read();
}

// Setter
void AnalogStick::begin() {
    up.begin();
    down.begin();
    left.begin();
    right.begin();

    select.begin();
}

void AnalogStick::enable() {
    up.enable();
    down.enable();
    left.enable();
    right.enable();

    select.enable();
}

void AnalogStick::disable() {
    up.disable();
    down.disable();
    left.disable();
    right.disable();

    select.disable();
}

void AnalogStick::reset() {
    up.reset();
    down.reset();
    left.reset();
    right.reset();

    select.reset();
}

void AnalogStick::update() {
    up.update();
    down.update();
    left.update();
    right.update();

    select.update();

    if (callback) callback(left.getValue(), up.getValue(), select.getState().state);
}

void AnalogStick::setX(int xVal) {
    left.update(xVal);
    right.update(xVal);
}

void AnalogStick::setY(int yVal) {
    up.update(yVal);
    down.update(yVal);
}

void AnalogStick::setPin(int xPin, int yPin, int selectPin) {
    up.setPin(yPin);
    down.setPin(yPin);
    left.setPin(xPin);
    right.setPin(xPin);

    select.setPin(selectPin);
}

void AnalogStick::setUpdateInterval(unsigned int interval) {
    up.setUpdateInterval(interval);
    down.setUpdateInterval(interval);
    left.setUpdateInterval(interval);
    right.setUpdateInterval(interval);

    select.setUpdateInterval(interval);
}

void AnalogStick::setPushTime(unsigned int pushTime) {
    up.setPushTime(pushTime);
    down.setPushTime(pushTime);
    left.setPushTime(pushTime);
    right.setPushTime(pushTime);

    select.setPushTime(pushTime);
}

void AnalogStick::setReleaseTime(unsigned int releaseTime) {
    up.setReleaseTime(releaseTime);
    down.setReleaseTime(releaseTime);
    left.setReleaseTime(releaseTime);
    right.setReleaseTime(releaseTime);

    select.setReleaseTime(releaseTime);
}

void AnalogStick::setTimeSpan(unsigned int timeSpan) {
    up.setTimeSpan(timeSpan);
    down.setTimeSpan(timeSpan);
    left.setTimeSpan(timeSpan);
    right.setTimeSpan(timeSpan);

    select.setTimeSpan(timeSpan);
}

void AnalogStick::setHoldInterval(unsigned int holdInterval) {
    up.setHoldInterval(holdInterval);
    down.setHoldInterval(holdInterval);
    left.setHoldInterval(holdInterval);
    right.setHoldInterval(holdInterval);

    select.setHoldInterval(holdInterval);
}

void AnalogStick::setCallback(analogstick_callback callback) {
    this->callback = callback;
}