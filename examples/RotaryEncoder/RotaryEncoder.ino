#include <SimpleButton.h>

using namespace simpleButton;

/*
   1 Rotary encoder is connected to a Wemos D1 mini (ESP8266)
   - Rotary encoder "Key" (that's the button) is connected to gpio 12 (D6)
   - Rotary encoder "S1" is connected to gpio 5 (D1) - that's channel A
   - Rotary encoder "S4" is connected to gpio 4 (D2) - that's channel B
   (the labels on your rotary encoder might be different!)
 */

RotaryEncoder* rotaryEncoder = NULL;

void setup() {
    Serial.begin(115200);
    Serial.println();

    rotaryEncoder = new RotaryEncoder(5, 4, 12);
    // rotaryEncoder->setSteps(2); // default = 1

    Serial.println("Started");
}

void loop() {
    rotaryEncoder->update();

    if (rotaryEncoder->button->doubleClicked()) Serial.println("doubleclicked");
    if (rotaryEncoder->button->clicked()) Serial.println("clicked");
    if (rotaryEncoder->button->holding()) Serial.println("holding");

    if (rotaryEncoder->clockwise->clicked()) Serial.println("up");
    if (rotaryEncoder->anticlockwise->clicked()) Serial.println("down");
}