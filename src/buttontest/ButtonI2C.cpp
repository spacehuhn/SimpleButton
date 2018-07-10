#include "ButtonI2C.h"

ButtonI2C::ButtonI2C(uint8_t i2cAddress, uint8_t address) {
  ButtonI2C::i2cAddress = i2cAddress;
  ButtonI2C::address = address;
  Button::enable();
}

ButtonI2C::~ButtonI2C() {

}

void ButtonI2C::update() {
  Wire.requestFrom((int)i2cAddress, 1);
  byte data = Wire.read();
  bool state = (~data & address) > 0;
  Button::update(state);
}

void ButtonI2C::enable() {
  Button::enable();
}

