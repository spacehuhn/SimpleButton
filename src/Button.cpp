#include "Button.h"

#include "Arduino.h" // pinMode, digitalRead, ...

Button::Button(int pin, int mode) {
    config.pin             = pin;
    config.mode            = mode;
    config.update_interval = 5;
    config.push_time       = 40;
    config.release_time    = 40;
    config.time_span       = 500;
    config.hold_interval   = 500;

    state.enabled           = true;
    state.state             = mode != BUTTON_DEFAULT;
    state.pushed            = false;
    state.released          = false;
    state.prev_released     = false;
    state.clicked           = false;
    state.double_clicked    = false;
    state.holding           = false;
    state.clicks            = 0;
    state.push_time         = 0;
    state.release_time      = 0;
    state.prev_push_time    = 0;
    state.prev_release_time = 0;
    state.holding_time      = 0;
    state.update_time       = 0;
}

// Getter
int Button::read() const {
    bool current_state = false;

    if (enabled()) {
        current_state = digitalRead(config.pin);
    }

    if (inverted()) current_state = !current_state;
    return (int)current_state;
}

bool Button::enabled() const {
    return state.enabled;
}

bool Button::inverted() const {
    return config.mode != BUTTON_DEFAULT;
}

bool Button::pushed() {
    if (enabled() && state.pushed) {
        state.pushed = false;
        return true;
    }
    return false;
}

bool Button::released() {
    if (enabled() && state.released) {
        state.released      = false;
        state.prev_released = true;

        return true;
    }
    return false;
}

bool Button::clicked() {
    if (enabled() && state.clicked) {
        state.clicked       = false;
        state.released      = false;
        state.prev_released = false;

        return true;
    }
    return false;
}

bool Button::doubleClicked() {
    if (enabled() && state.double_clicked) {
        state.double_clicked = false;
        return true;
    }
    return false;
}

bool Button::holding() {
    if (enabled() && state.holding) {
        state.holding = false;
        return true;
    }
    return false;
}

int Button::getClicks() const {
    return state.clicks;
}

button_state Button::getState() const {
    return state;
};

button_config Button::getConfig() const {
    return config;
};


// Setter
void Button::begin() {
    if (config.pin >= 0) {
        pinMode(config.pin, config.mode == BUTTON_PULLUP ? INPUT_PULLUP : INPUT);
        enable();

        state.enabled        = true;
        state.state          = read();
        state.pushed         = false;
        state.released       = false;
        state.prev_released  = false;
        state.clicked        = false;
        state.double_clicked = false;
        state.holding        = false;
        // state.clicks            = 0;
        state.push_time         = 0;
        state.release_time      = 0;
        state.prev_push_time    = 0;
        state.prev_release_time = 0;
        state.holding_time      = 0;
        state.update_time       = 0;
    }
}

void Button::enable() {
    state.enabled = true;
}

void Button::disable() {
    state.enabled = false;
}

void Button::reset() {
    state.pushed   = false;
    state.released = false;
    state.holding  = false;
}

void Button::push() {
    if (!state.state) {
        state.prev_push_time    = state.push_time;
        state.prev_release_time = state.release_time;
        state.push_time         = millis();
        state.holding_time      = state.push_time;

        state.state         = true;
        state.pushed        = true;
        state.released      = false;
        state.holding       = false;
        state.prev_released = false;
    }
}

void Button::release() {
    if (state.state) {
        state.release_time = millis();

        state.state         = false;
        state.pushed        = false;
        state.released      = true;
        state.holding       = false;
        state.prev_released = false;
    }
}

void Button::click() {
    click(config.push_time);
}

void Button::click(unsigned int time) {
    state.release_time = millis() - config.release_time;
    state.push_time    = state.holding_time = state.release_time - time;

    state.state    = false;
    state.released = true;
    state.holding  = false;
}

void Button::doubleclick() {
    state.release_time      = millis() - config.release_time;
    state.push_time         = state.holding_time = state.release_time - config.push_time;
    state.prev_release_time = state.push_time - config.release_time;
    state.prev_push_time    = state.prev_release_time - config.push_time;

    state.state    = false;
    state.released = true;
    state.holding  = false;
}

void Button::update() {
    if ((millis() - state.update_time >= config.update_interval) && enabled()) {
        update(read());
    }
}

void Button::update(int newState) {
    state.update_time = millis();

    // Pushed, Released
    if (newState > 0) {
        push();
    } else {
        release();
    }

    // Holding
    if (newState && (millis() - state.holding_time >= config.hold_interval)) {
        state.holding_time = millis();
        state.holding      = true;
    }

    // Clicked, Double-clicked
    if (state.released || state.prev_released) {
        unsigned long pushTime    = state.release_time - state.push_time;
        unsigned long releaseTime = millis() - state.release_time;

        if ((pushTime >= config.push_time) && (pushTime < config.hold_interval) && (releaseTime >= config.release_time)) {
            ++state.clicks;
            state.clicked = true;

            unsigned long prevPushTime    = state.prev_release_time - state.prev_push_time;
            unsigned long prevReleaseTime = state.push_time - state.prev_release_time;
            unsigned long timespan        = millis() - state.prev_push_time;

            if ((prevPushTime >= config.push_time) && (prevPushTime < config.hold_interval) && (prevReleaseTime >= config.release_time) && (timespan<= config.time_span)) {
                state.double_clicked = true;
            }
        }
    }

    if (onPushed && pushed()) onPushed();
    if (onReleased && released()) onReleased();
    if (onClicked && clicked()) onClicked();
    if (onDoubleClicked && doubleClicked()) onDoubleClicked();
    if (onHolding && holding()) onHolding();
}

void Button::setPin(int pin, int mode) {
    config.pin  = pin;
    config.mode = mode;
}

void Button::setInverted(int mode) {
    config.mode = mode;
}

void Button::setUpdateInterval(unsigned int interval) {
    config.update_interval = interval;
}

void Button::setPushTime(unsigned int pushTime) {
    config.push_time = pushTime;
}

void Button::setReleaseTime(unsigned int releaseTime) {
    config.release_time = releaseTime;
}

void Button::setTimeSpan(unsigned int timeSpan) {
    config.time_span = timeSpan;
}

void Button::setHoldInterval(unsigned int holdInterval) {
    config.hold_interval = holdInterval;
}

void Button::setOnPushed(button_callback onPushed) {
    this->onPushed = onPushed;
}

void Button::setOnReleased(button_callback onReleased) {
    this->onReleased = onReleased;
}

void Button::setOnClicked(button_callback onClicked) {
    this->onClicked = onClicked;
}

void Button::setOnDoubleClicked(button_callback onDoubleClicked) {
    this->onDoubleClicked = onDoubleClicked;
}

void Button::setOnHolding(button_callback onHolding) {
    this->onHolding = onHolding;
}