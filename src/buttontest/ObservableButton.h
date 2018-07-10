#ifndef ObservableButton_h
#define ObservableButton_h

#include "Arduino.h"
#include "Button.h"

class ObservableButton {
  public:
    ObservableButton(Button* button);
    ~ObservableButton();

    void update();

    void setOnPushed(void (*onPushed)());
    void setOnClicked(void (*onClicked)());
    void setOnLongClicked(uint32_t time, void (*onLongClicked)());
    void setOnHolded(uint32_t time, void (*onHold)());
    
  private:
    Button* button = NULL;

    uint32_t clickTime = 0;
    uint32_t holdTime = 0;
    
    void (*onPushed)() = NULL;
    void (*onClicked)() = NULL;
    void (*onLongClicked)() = NULL;
    void (*onHold)() = NULL;
};

#endif
