#include "Button.h"
#include "ButtonI2C.h"
#include "ObservableButton.h"
#include <Wire.h>

Button* buttonUp;
Button* buttonDown;
Button* buttonLeft;
Button* buttonRight;
Button* buttonA;
Button* buttonB;
Button* buttonC;
Button* buttonSD;

ObservableButton* up = NULL;

void setupI2CButtons(){
  #define ADDR_I2C_BUTTONS 0x27
  #define ADDR_BUTTON_UP    B10000000
  #define ADDR_BUTTON_DOWN  B00100000
  #define ADDR_BUTTON_LEFT  B01000000
  #define ADDR_BUTTON_RIGHT B00010000
  #define ADDR_BUTTON_A     B00000100
  #define ADDR_BUTTON_B     B00001000
  #define ADDR_BUTTON_C     B00000001
  #define ADDR_BUTTON_SD    B00000010

  buttonUp = new ButtonI2C(ADDR_BUTTON_UP, ADDR_I2C_BUTTONS);
  buttonDown = new ButtonI2C(ADDR_BUTTON_DOWN, ADDR_I2C_BUTTONS);
  buttonLeft = new ButtonI2C(ADDR_BUTTON_LEFT, ADDR_I2C_BUTTONS);
  buttonRight = new ButtonI2C(ADDR_BUTTON_RIGHT, ADDR_I2C_BUTTONS);
  buttonA = new ButtonI2C(ADDR_BUTTON_A, ADDR_I2C_BUTTONS);
  buttonB = new ButtonI2C(ADDR_BUTTON_B, ADDR_I2C_BUTTONS);
  buttonC = new ButtonI2C(ADDR_BUTTON_C, ADDR_I2C_BUTTONS);
  buttonSD = new ButtonI2C(ADDR_BUTTON_SD, ADDR_I2C_BUTTONS);
}

void setupButton(){
  buttonUp = new Button(10);
  buttonDown = new Button(9);
  buttonLeft = new Button(0);
  buttonRight = new Button(13);
  buttonA = new Button(14);
  buttonB = new Button(12);
}

void setup() {
  Serial.begin(115200);
  Wire.begin(5,4);

  setupI2CButtons();
  //setupButton();

  up = new ObservableButton(buttonUp);
  up->setOnClicked([](){
    Serial.println("clicked");
  });
  up->setOnLongClicked(500, [](){
    Serial.println("long clicked");
  });
  up->setOnHolded(1000, [](){
    Serial.println("holding");
  });
  
  delay(1000);
  
  Serial.println();
  Serial.println("hi");
}

bool upState = false;

void loop() {
  buttonUp->update();
  buttonDown->update();
  buttonLeft->update();
  buttonRight->update();
  buttonA->update();
  buttonB->update();
  buttonC->update();
  buttonSD->update();

  //up->update();
  
  //buttonC->update();
  //buttonSD->update();
  
  /*if(!upState && buttonUp->pushed()){
    Serial.println("UP push");
    upState = !upState;
  }*/
  /*if(buttonDown->pushed()) Serial.println("DOWN push");
  if(buttonLeft->pushed()) Serial.println("LEFT push");
  if(buttonRight->pushed()) Serial.println("RIGHT push");
  if(buttonA->pushed()) Serial.println("A push");
  if(buttonB->pushed()) Serial.println("B push");*/

  /*if(upState && !buttonUp->pushed()){
    Serial.println("UP not pushed");
    upState = !upState;
  }*/
  /*if(!buttonDown->pushed()) Serial.println("DOWN not pushed");
  if(!buttonLeft->pushed()) Serial.println("LEFT not pushed");
  if(buttonRight->pushed()) Serial.println("RIGHT not pushed");
  if(!buttonA->pushed()) Serial.println("A not pushed");
  if(!buttonB->pushed()) Serial.println("B not pushed");*/
  /*
  if(buttonUp->holded(1000)) Serial.println("UP holding");
  if(buttonDown->holded(1000)) Serial.println("DOWN holding");
  if(buttonLeft->holded(1000)) Serial.println("LEFT holding");
  if(buttonRight->holded(1000)) Serial.println("RIGHT holding");
  if(buttonA->holded(1000)) Serial.println("A holding");
  if(buttonB->holded(1000)) Serial.println("B holding");
  */
  
  if(buttonUp->pushed()) Serial.println("UP pushed");
  if(buttonDown->pushed()) Serial.println("DOWN pushed");
  if(buttonLeft->pushed()) Serial.println("LEFT pushed");
  if(buttonRight->pushed()) Serial.println("RIGHT pushed");
  if(buttonA->pushed()) Serial.println("A pushed");
  if(buttonB->pushed()) Serial.println("B pushed");
  if(buttonC->pushed()) Serial.println("C pushed");
  if(buttonSD->pushed()) Serial.println("SD pushed");
/*
  if(buttonUp->clicked()) Serial.println("UP clicked");
  if(buttonDown->clicked()) Serial.println("DOWN clicked");
  if(buttonLeft->clicked()) Serial.println("LEFT clicked");
  if(buttonRight->clicked()) Serial.println("RIGHT clicked");
  if(buttonA->clicked()) Serial.println("A clicked");
  if(buttonB->clicked()) Serial.println("B clicked");
  if(buttonC->clicked()) Serial.println("C clicked");
  if(buttonSD->clicked()) Serial.println("SD clicked");
  */
/*
  if(buttonUp->clicked(500)) Serial.println("UP long clicked");
  if(buttonDown->clicked(500)) Serial.println("DOWN long clicked");
  if(buttonLeft->clicked(500)) Serial.println("LEFT long clicked");
  if(buttonRight->clicked(500)) Serial.println("RIGHT long clicked");
  if(buttonA->clicked(500)) Serial.println("A long clicked");
  if(buttonB->clicked(500)) Serial.println("B long clicked");
  
  if(buttonUp->clicked(100)) Serial.println("UP short clicked");
  if(buttonDown->clicked(100)) Serial.println("DOWN short clicked");
  if(buttonLeft->clicked(100)) Serial.println("LEFT short clicked");
  if(buttonRight->clicked(100)) Serial.println("RIGHT short clicked");
  if(buttonA->clicked(100)) Serial.println("A short clicked");
  if(buttonB->clicked(100)) Serial.println("B short clicked");
  */
  //if(buttonC->holded(1000) || buttonC->clicked()) Serial.println("C");
  //if(buttonSD->holded(1000) || buttonSD->clicked()) Serial.println("SD");
}
