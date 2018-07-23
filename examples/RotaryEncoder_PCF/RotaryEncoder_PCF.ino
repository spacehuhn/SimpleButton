#include <SimpleButton.h>

using namespace simpleButton;

/*
   1 Rotary encoder is connected to a PCF8574 on a Wemos D1 mini (ESP8266)
   - PCF8574 is connected with SDA to GPIO 5 (D1) and with SCL to GPIO 4 (D2)
   - Rotary encoder CLK is connected to the PCF pin 0 - that's channel A
   - Rotary encoder DT is connected to PCF pin 1 - that's channel B
   (the labels on your rotary encoder might be different!)
 */

PCF8574* myPCF               = NULL;
RotaryEncoder* rotaryEncoder = NULL;

void setup() {
    // for non-ESP Arduino's, just do Wire.begin();
    Wire.begin(5, 4);
    Wire.setClock(700000);

    Serial.begin(115200);
    Serial.println();

    myPCF = new PCF8574(0x20); // 0x20 = i2c address (use a i2c scanner sketch to find the right address)

    rotaryEncoder = new RotaryEncoder(myPCF, 0, 1);

    Serial.println("Started");
}

void loop() {
    rotaryEncoder->update();

    if (rotaryEncoder->clockwise->clicked()) Serial.println("down");
    if (rotaryEncoder->anticlockwise->clicked()) Serial.println("up");
}