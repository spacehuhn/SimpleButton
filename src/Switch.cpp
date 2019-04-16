#include "Switch.h"

#include "Arduino.h" // pinMode, digitalRead, millis, ...

Switch::Switch(int pin, int mode) {
    config.pin             = pin;
    config.mode            = mode;
    config.update_interval = 5;
    config.switch_delay    = 40;

    state.enabled      = false;
    state.state        = mode != SWITCH_DEFAULT;
    state.prev_state   = state.state;
    state.pushed       = false;
    state.released     = false;
    state.switched     = false;
    state.switched_on  = false;
    state.switched_off = false;
    state.switches     = 0;
    state.switch_time  = 0;
    state.update_time  = 0;
}

// Getter
int Switch::read() const {
    bool current_state = false;

    if (enabled()) {
        current_state = digitalRead(config.pin);
    }

    if (inverted()) current_state = !current_state;
    return (int)current_state;
}

bool Switch::enabled() const {
    return state.enabled;
}

bool Switch::inverted() const {
    return config.mode != SWITCH_DEFAULT;
}

bool Switch::pushed() {
    if (enabled() && state.pushed) {
        state.pushed = false;
        return true;
    }
    return false;
}

bool Switch::released() {
    if (enabled() && state.released) {
        state.released = false;
        return true;
    }
    return false;
}

bool Switch::switched() {
    if (enabled() && state.switched) {
        state.switched = false;
        return true;
    }
    return false;
}

bool Switch::switchedOn() {
    if (enabled() && state.switched_on) {
        state.switched_on = false;
        return true;
    }
    return false;
}

bool Switch::switchedOff() {
    if (enabled() && state.switched_off) {
        state.switched_off = false;
        return true;
    }
    return false;
}

int Switch::getSwitches() const {
    return state.switches;
}

switch_state Switch::getState() const {
    return state;
}

switch_config Switch::getConfig() const {
    return config;
}

// Setter
void Switch::begin() {
    if (config.pin >= 0) {
        pinMode(config.pin, config.mode == SWITCH_PULLUP ? INPUT_PULLUP : INPUT);
        enable();

        state.state        = read();
        state.prev_state   = state.state;
        state.pushed       = false;
        state.released     = false;
        state.switched     = false;
        state.switched_on  = false;
        state.switched_off = false;
        // state.switches     = 0;
        state.switch_time = 0;
        state.update_time = 0;
    }
}

void Switch::enable() {
    state.enabled = true;
}

void Switch::disable() {
    state.enabled = false;
}

void Switch::reset() {
    state.switched     = false;
    state.switched_on  = false;
    state.switched_off = false;
}

void Switch::push() {
    if (!state.state) {
        state.switch_time = millis();

        state.prev_state = false;
        state.state      = true;
        state.pushed     = true;
        state.released   = false;
    }
}

void Switch::release() {
    if (state.state) {
        state.switch_time = millis();

        state.prev_state = true;
        state.state      = false;
        state.pushed     = false;
        state.released   = true;
    }
}

void Switch::switch_() {
    if (state.state) {
        switchOff();
    } else {
        switchOn();
    }
}

void Switch::switchOn() {
    state.prev_state = state.state;
    state.state      = false;

    state.switched     = true;
    state.switched_on  = true;
    state.switched_off = false;

    state.switch_time = millis() - config.switch_delay;
}

void Switch::switchOff() {
    state.prev_state = state.state;
    state.state      = false;

    state.switched     = true;
    state.switched_on  = false;
    state.switched_off = true;

    state.switch_time = millis() - config.switch_delay;
}

void Switch::update() {
    if ((millis() - state.update_time >= config.update_interval) && enabled()) {
        update(read());
    }
}

void Switch::update(int newState) {
    state.update_time = millis();

    // Pushed, Released
    if (newState > 0) {
        push();
    } else {
        release();
    }

    // Switched on/off
    if ((state.state != state.prev_state) && (millis() - state.switch_time >= config.switch_delay)) {
        if (state.state) {
            state.switched     = true;
            state.switched_on  = true;
            state.switched_off = false;
        } else {
            state.switched     = true;
            state.switched_on  = false;
            state.switched_off = true;
        }
        state.prev_state = state.state;
    }

    if (onPushed && pushed()) onPushed();
    if (onReleased && released()) onReleased();
    if (onSwitched && switched()) onSwitched();
    if (onSwitchedOn && switchedOn()) onSwitchedOn();
    if (onSwitchedOff && switchedOff()) onSwitchedOff();
}

void Switch::setPin(int pin, int mode) {
    config.pin  = pin;
    config.mode = mode;
}

void Switch::setInverted(int mode) {
    config.mode = mode;
}

void Switch::setUpdateInterval(unsigned int interval) {
    config.update_interval = interval;
}

void Switch::setSwitchDelay(unsigned int switchDelay) {
    config.switch_delay = switchDelay;
}

void Switch::setOnPushed(switch_callback onPushed) {
    this->onPushed = onPushed;
}

void Switch::setOnReleased(switch_callback onReleased) {
    this->onReleased = onReleased;
}

void Switch::setOnSwitched(switch_callback onSwitched) {
    this->onSwitched = onSwitched;
}

void Switch::setOnSwitchedOn(switch_callback onSwitchedOn) {
    this->onSwitchedOn = onSwitchedOn;
}

void Switch::setOnSwitchedOff(switch_callback onSwitchedOff) {
    this->onSwitchedOff = onSwitchedOff;
}