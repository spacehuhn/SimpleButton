#ifndef ButtonI2C_h
#define ButtonI2C_h

#include "Arduino.h"
#include "Button.h"
#include "Wire.h"

class ButtonI2C: public Button {
  public:
    ButtonI2C();
    ButtonI2C(uint8_t i2cAddress, uint8_t address);
    ~ButtonI2C();
    
    void update();
    void enable();
  private:
    uint8_t address = 0;
    uint8_t i2cAddress = 0;
};

#endif
