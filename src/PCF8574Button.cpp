#include "PCF8574Button.h"

namespace simpleButton {
    PCF8574Button::PCF8574Button() {
        enable();
    }

    PCF8574Button::PCF8574Button(Button* button, PCF8574* pcf, uint8_t pin) {
        this->button     = button;
        this->pcf        = pcf;
        this->button_pin = pin;
        enable();
    }

    PCF8574Button::~PCF8574Button() {
        if (button) delete button;
    }

    void PCF8574Button::enable() {
        button_enabled = true;

        if (button && pcf && (button_pin < 8)) {
            button->enable();
            button_setup = true;

            pcf->write(button_pin, button->isInverted());
        }
    }

    void PCF8574Button::disable() {
        button_enabled = false;

        if (button) button->disable();
    }

    void PCF8574Button::push() {
        if (button) button->push();
    }

    void PCF8574Button::release() {
        if (button) button->release();
    }

    void PCF8574Button::click() {
        if (button) button->click();
    }

    void PCF8574Button::click(uint32_t time) {
        if (button) button->click(time);
    }

    bool PCF8574Button::read() {
        if (button_enabled && button_setup) {
            return pcf->read(button_pin) == 0;
        }

        return false;
    }

    void PCF8574Button::update() {
        if (button_enabled && button_setup) {
            bool newState = read();

            if (button->isInverted()) newState = !newState;
            update(newState);
        }
    }

    void PCF8574Button::update(bool state) {
        if (button) button->update(state);
    }

    bool PCF8574Button::isEnabled() {
        return button_enabled;
    }

    bool PCF8574Button::isSetup() {
        return button_setup;
    }

    bool PCF8574Button::getState() {
        return button ? button->getState() : false;
    }

    int PCF8574Button::getClicks() {
        return button ? button->getClicks() : 0;
    }

    int PCF8574Button::getPushTime() {
        return button ? button->getPushTime() : 0;
    }

    bool PCF8574Button::pushed() {
        return button ? button->pushed() : false;
    }

    bool PCF8574Button::released() {
        return button ? button->released() : false;
    }

    bool PCF8574Button::clicked() {
        return button ? button->clicked() : false;
    }

    bool PCF8574Button::clicked(uint32_t minPushTime) {
        return button ? button->clicked(minPushTime) : false;
    }

    bool PCF8574Button::doubleClicked() {
        return button ? button->doubleClicked() : false;
    }

    bool PCF8574Button::doubleClicked(uint32_t minPushTime) {
        return button ? button->doubleClicked(minPushTime) : false;
    }

    bool PCF8574Button::doubleClicked(uint32_t minPushTime, uint32_t timeSpan) {
        return button ? button->doubleClicked(minPushTime, timeSpan) : false;
    }

    bool PCF8574Button::holded() {
        return button ? button->holded() : false;
    }

    bool PCF8574Button::holded(uint32_t interval) {
        return button ? button->holded(interval) : false;
    }
}