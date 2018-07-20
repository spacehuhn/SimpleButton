#include <SimpleButton.h>

using namespace simpleButton;

/*
  Analog joystick connected to an Arduino micro
  - x axis is connected to pin A0
  - y axis is connected to pin A1
  - Switch is connected to pin 5
*/

Button* left = NULL;
Button* right = NULL;
Button* up = NULL;
Button* down = NULL;
Button* key = NULL;

void setup() {
  Serial.begin(115200);
  Serial.println();

  left = new ButtonAnalog(A0, 0, 256);
  right = new ButtonAnalog(A0, 768, 1024);
  up = new ButtonAnalog(A1, 0, 256);
  down = new ButtonAnalog(A1, 768, 1024);
  key = new ButtonPullup(5);

  Serial.println("Started!");
}

void loop() {
  left->update();
  right->update();
  up->update();
  down->update();
  key->update();

  if(left->clicked()) Serial.println("left clicked");
  if(right->clicked()) Serial.println("right clicked");
  if(up->clicked()) Serial.println("up clicked");
  if(down->clicked()) Serial.println("down clicked");
  
  if(left->holded()) Serial.println("left holded");
  if(right->holded()) Serial.println("right holded");
  if(up->holded()) Serial.println("up holded");
  if(down->holded()) Serial.println("down holded");
  
  if(key->clicked()) Serial.println("clicked");
}