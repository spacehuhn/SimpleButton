#include <SimpleButton.h>

using namespace simpleButton;

/*
   1 Rotary encoder is connected to a Wemos D1 mini (ESP8266)
   - Rotary encoder "Key" (that's the button) is connected to gpio 12 (D6)
   - Rotary encoder "S1" is connected to gpio 5 (D1) - that's channel A
   - Rotary encoder "S4" is connected to gpio 4 (D2) - that's channel B
   (the labels on your rotary encoder might be different!)
 */

Button* bKey  = NULL;
Button* bUp   = NULL;
Button* bDown = NULL;

void setup() {
    Serial.begin(115200);
    Serial.println();

    bKey = new ButtonPullup(12);

    // uncomment the "2" if you have a rotary encoder with x1 encoding
    // (in simpler words: if you get "up" or "down" twice with each step, you need to uncomment the 2)
    bUp   = new RotaryEncoder(5, NULL /*, 2*/);
    bDown = new RotaryEncoder(4, bUp /*, 2*/);

    // ^ Note that you have need 2 buttons, because you have 2 channels to read out the rotary encoder.
    // The first button is just there to read out it's own state.
    // The second one needs a pointer to the first, that way it can figure out in which direction it's going.

    Serial.begin(115200);

    Serial.println("Started");
}

void loop() {
    bKey->update();
    bUp->update();
    bDown->update();

    if (bKey->doubleClicked()) Serial.println("doubleclicked");

    if (bKey->clicked()) Serial.println("clicked");

    if (bKey->held()) Serial.println("held");

    if (bUp->clicked()) Serial.println("up");

    if (bDown->clicked()) Serial.println("down");
}