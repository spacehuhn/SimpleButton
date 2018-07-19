#include <SimpleButton.h>

using namespace simpleButton;

/*
   A on/off switch is connected to gpio 12
   - the switch connects gpio 12 to either VCC (3.3V) or GND
 */

Button* b = NULL;

void setup() {
    Serial.begin(115200);
    Serial.println();

    b = new Switch(12);

    Serial.println("Started");
}

void loop() {
    b->update();

    if (b->clicked()) Serial.println("clicked");
}