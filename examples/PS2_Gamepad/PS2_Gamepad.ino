#include <SimpleButton.h>

using namespace simpleButton;

/*
   // Arduino Nano
 #define DATA_PIN        13
 #define COMMAND_PIN     11
 #define ATTENTION_PIN   10
 #define CLOCK_PIN       12
 */

// Wemos D1 mini
#define DATA_PIN       5 // D1
#define COMMAND_PIN   12 // D6
#define ATTENTION_PIN 14 // D5
#define CLOCK_PIN     13 // D7

PS2Gamepad* gamepad = NULL;

void setup() {
    Serial.begin(115200);
    Serial.println();

    // create gamepad
    gamepad = new PS2Gamepad();

    // try connecting to it
    while (!gamepad->isEnabled()) {
        Serial.print("Connecting to PlayStation-2 Controller...");

        // setup
        gamepad->setup(CLOCK_PIN, COMMAND_PIN, ATTENTION_PIN, DATA_PIN);

        // print OK or error message
        Serial.println(gamepad->getError());

        // retry if connection failed
        if (!gamepad->isEnabled()) {
            Serial.println("Retrying...");
            delay(1000);
        }
    }

    Serial.println("Started");
}

void loop() {
    gamepad->update();

    // print analog values

    /*
       uint8_t left_x = gamepad->analogLeft->up->getValue();
       uint8_t left_y = gamepad->analogLeft->left->getValue();
       uint8_t right_x = gamepad->analogRight->up->getValue();
       uint8_t right_y = gamepad->analogRight->left->getValue();
       Serial.printf("Left-X: %+3u, Left-Y: %+3u, Right-X: %+3u, Right-Y: %+3u\n", left_x, left_y, right_x, right_y);
     */

    // d-pad
    if (gamepad->up->clicked()) Serial.println("up clicked");
    if (gamepad->up->holding()) Serial.println("up holding");

    if (gamepad->down->holding()) Serial.println("down clicked");
    if (gamepad->down->clicked()) Serial.println("down holding");

    if (gamepad->left->clicked()) Serial.println("left clicked");
    if (gamepad->left->holding()) Serial.println("left holding");

    if (gamepad->right->clicked()) Serial.println("right clicked");
    if (gamepad->right->holding()) Serial.println("right holding");

    // L and R Buttons
    if (gamepad->l1->clicked()) Serial.println("L1 clicked");
    if (gamepad->l1->holding()) Serial.println("L1 holding");

    if (gamepad->l2->clicked()) Serial.println("L2 clicked");
    if (gamepad->l2->holding()) Serial.println("L2 holding");

    if (gamepad->r1->clicked()) Serial.println("R1 clicked");
    if (gamepad->r1->holding()) Serial.println("R1 holding");

    if (gamepad->r2->clicked()) Serial.println("R2 clicked");
    if (gamepad->r2->holding()) Serial.println("R2 holding");

    // start & select
    if (gamepad->select->clicked()) Serial.println("Select clicked");
    if (gamepad->select->holding()) Serial.println("Select holding");

    if (gamepad->start->clicked()) Serial.println("Start clicked");
    if (gamepad->start->holding()) Serial.println("Start holding");

    // triangle, circle, cross, square
    if (gamepad->square->clicked()) Serial.println("Square clicked");
    if (gamepad->square->holding()) Serial.println("Square holding");

    if (gamepad->triangle->clicked()) Serial.println("Triangle clicked");
    if (gamepad->triangle->holding()) Serial.println("Triangle holding");

    if (gamepad->x->clicked()) Serial.println("X clicked");
    if (gamepad->x->holding()) Serial.println("X holding");

    if (gamepad->circle->clicked()) Serial.println("Circle clicked");
    if (gamepad->circle->holding()) Serial.println("Circle holding");

    // analog sticks
    if (gamepad->analogLeft->button->clicked()) Serial.println("Stick-Left clicked");
    if (gamepad->analogLeft->button->holding()) Serial.println("Stick-Left holding");

    if (gamepad->analogLeft->up->holding()) Serial.println("Stick-Left up");
    if (gamepad->analogLeft->down->holding()) Serial.println("Stick-Left down");
    if (gamepad->analogLeft->left->holding()) Serial.println("Stick-Left left");
    if (gamepad->analogLeft->right->holding()) Serial.println("Stick-Left right");


    if (gamepad->analogRight->button->clicked()) Serial.println("Stick-Right clicked");
    if (gamepad->analogRight->button->holding()) Serial.println("Stick-Right holding");

    if (gamepad->analogRight->up->holding()) Serial.println("Stick-Right up");
    if (gamepad->analogRight->down->holding()) Serial.println("Stick-Right down");
    if (gamepad->analogRight->left->holding()) Serial.println("Stick-Right left");
    if (gamepad->analogRight->right->holding()) Serial.println("Stick-Right right");
}