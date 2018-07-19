#include <SimpleButton.h>
#include <Wire.h>

using namespace simpleButton;

/*
   This example is for the Lameboy by @davedarko
   https://hackaday.io/project/26823-lameboy-another-esp12-handheld
   https://www.tindie.com/products/davedarko/lameboy-esp8266-handheld
 */

Button* up    = NULL;
Button* down  = NULL;
Button* left  = NULL;
Button* right = NULL;
Button* a     = NULL;
Button* b     = NULL;
Button* sd    = NULL;

PCF8574* myPCF = NULL;

void setup() {
    Serial.begin(115200);
    Serial.println();

    Wire.begin();

    myPCF = new PCF8574(0x3C); // 0x3c = i2c address (use a i2c scanner sketch to find the right address)

    up    = new ButtonPCF(new ButtonPullup(), myPCF, 7);
    down  = new ButtonPCF(new ButtonPullup(), myPCF, 5);
    left  = new ButtonPCF(new ButtonPullup(), myPCF, 6);
    right = new ButtonPCF(new ButtonPullup(), myPCF, 4);
    a     = new ButtonPCF(new ButtonPullup(), myPCF, 3);
    b     = new ButtonPCF(new ButtonPullup(), myPCF, 2);
    sd    = new ButtonPCF(new ButtonPullup(), myPCF, 1);

    Serial.println("Started");
}

void loop() {
    up->update();
    down->update();
    left->update();
    right->update();
    a->update();
    b->update();
    sd->update();

    if (up->doubleClicked()) Serial.println("up doubleclicked");
    if (up->clicked()) Serial.println("up clicked");
    if (up->holded()) Serial.println("up holded");

    if (down->doubleClicked()) Serial.println("down doubleclicked");
    if (down->clicked()) Serial.println("down clicked");
    if (down->holded()) Serial.println("down holded");
    
    if (left->doubleClicked()) Serial.println("left doubleclicked");
    if (left->clicked()) Serial.println("left clicked");
    if (left->holded()) Serial.println("left holded");

    if (right->doubleClicked()) Serial.println("right doubleclicked");
    if (right->clicked()) Serial.println("right clicked");
    if (right->holded()) Serial.println("right holded");

    if (a->doubleClicked()) Serial.println("a doubleclicked");
    if (a->clicked()) Serial.println("a clicked");
    if (a->holded()) Serial.println("a holded");

    if (b->doubleClicked()) Serial.println("b doubleclicked");
    if (b->clicked()) Serial.println("b clicked");
    if (b->holded()) Serial.println("b holded");

    if (sd->pushed()) Serial.println("sd card inserted");
    if (sd->released()) Serial.println("sd card removed");
}