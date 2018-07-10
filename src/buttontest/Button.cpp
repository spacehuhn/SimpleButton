#include "Button.h"

Button::Button() {

}

Button::Button(uint8_t pin) {
  Button::pin = pin;
  pinMode(pin, INPUT_PULLUP);
  enable();
}

Button::~Button() {

}

void Button::enable() {
  enabled = true;
}

void Button::disable() {
  enabled = false;
}

void Button::update() {
  update(!digitalRead(pin));
}

void Button::update(bool state) {
  if (!enabled) return;

  uint32_t currentTime = millis();

  if(currentTime - updateTime < 25) return;
  updateTime = currentTime;

  bool prevState = isPushed;
  isPushed = state;
  
  if (isPushed && !prevState) {
    pushBeginTime = currentTime;
    holdTime = currentTime;
    holdFlag = false;
  }

  if (!isPushed && prevState) {
    if (currentTime - pushBeginTime > 40) clickedFlag = true;
    else Serial.println(currentTime - pushBeginTime);
  }
}

bool Button::pushed() {
  return isPushed;
}

bool Button::clicked() {
  if (clickedFlag) {
    clickedFlag = false;
    if(!holdFlag) return true;
  }

  return false;
}

bool Button::clicked(uint32_t time){
  if (clickedFlag && millis() - pushBeginTime >= time) {
    clickedFlag = false;
    if(!holdFlag) return true;
  }

  return false;
}

bool Button::holded(uint32_t interval) {
  if (isPushed && millis() - holdTime >= interval) {
    holdTime = millis();
    holdFlag = true;
    return true;
  }

  return false;
}

bool Button::isEnabled() {
  return enabled;
}

