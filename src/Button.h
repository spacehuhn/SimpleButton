#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
  public:
    Button();
    Button(uint8_t pin);
    ~Button();

    void enable();
    void disable();
    
    void update();
    void update(bool state);
    
    bool pushed();
    bool clicked();
    bool clicked(uint32_t time);
    bool holded(uint32_t interval);
    bool isEnabled();
    
  protected:
    bool enabled = false;
    bool isPushed = false;

    bool clickedFlag = false;
    bool holdFlag = false;
    
    uint32_t pushBeginTime = 0;
    uint32_t holdTime = 0;
    uint32_t updateTime = 0;
  private:
    uint8_t pin = 0;
};

#endif
