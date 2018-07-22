#include <SimpleButton.h>

using namespace simpleButton;

/*
   2 buttons are connected to a PCF8574 on a Wemos D1 mini (ESP8266)
   - PCF8574 is connected with SDA to GPIO 5 (D1) and with SCL to GPIO 4 (D2)
   - Button A is connected between the PCF pin 0 and GND
   - Button B is connected between the PCF pin 1 and 3.3V (VCC)
 */

PCF8574* myPCF   = NULL;
Button * buttonA = NULL;
Button * buttonB = NULL;

void setup() {
    // for non-ESP Arduino's, just do Wire.begin();
    Wire.begin(5, 4);
    Wire.setClock(700000);

    Serial.begin(115200);
    Serial.println();

    myPCF = new PCF8574(0x38); // 0x38 = i2c address (use a i2c scanner sketch to find the right address)

    buttonA = new ButtonPCF(new Button(255, true), myPCF, 0);
    buttonB = new ButtonPCF(new Button(255), myPCF, 1);
    // ^ note how button A has "true" in the constructor,
    // that's because it's connected to GND and therefor inverted in it's logic
    // the pins are set to 255 so the object knows it doesn't have to do the "pinmode()" setup procedure

    Serial.println("Started");
}

void loop() {
    buttonA->update();
    buttonB->update();

    if (buttonA->doubleClicked()) Serial.println("Button A doubleclicked");

    if (buttonA->clicked()) Serial.println("Button A clicked");

    if (buttonA->holding()) Serial.println("Button A holding");

    if (buttonB->doubleClicked()) Serial.println("Button B doubleclicked");

    if (buttonB->clicked()) Serial.println("Button B clicked");

    if (buttonB->holding()) Serial.println("Button B holding");
}
