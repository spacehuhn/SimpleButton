# SimpleButton
A simple Arduino library to make interfacing and reacting on button events easier.

## Features

This libary supports:  
- Push buttons (with or without pullup or inverted logic)
- On/Off Switches
- Rotary Encoders
- The [Lameboy](https://hackaday.io/project/26823-lameboy-another-esp12-handheld) :D
- Any Analog input (i.e. ButtonMatrix)
- AnalogStick
- PlayStation2 Gamepad

You can not only read out the current state of the button, but also if it's:    
- pushed
- released
- clicked
- doubleclicked
- holding

It also works with buttons that are connected to a PCF8574 or PCF8575 GPIO expander!  
For that my [PCF8574](https://github.com/spacehuhn/PCF8574) library is integrated, so you don't need to install any additional library.  

## To-Do:
- Add support for [I2C Encoder](https://www.tindie.com/products/Saimon/i2c-encoder-connect-rotary-encoders-on-i2c-bus/)
- Add support for MCP23017

(Currently waiting on my orders from China to add those :D)

## Installation

1) [Download](https://github.com/spacehuhn/SimpleButton/archive/master.zip) the source code from GitHub.  
2) Unzip and rename the Folder name to "SimpleButton".  
3) Paste it in your Library folder (Usually located somewhere at documents/Arduino/libraries).  
4) Restart the Arduino IDE.  

## Usage

Also have a look at the [examples](https://github.com/spacehuhn/SimpleButton/tree/master/examples).  

### Include the library
```c++
#include <SimpleButton.h>

using namespace simpleButton;
```

### Create a button

#### Push Button

**Normal logic:**  
The usual way of connecting a push button as descriped [here](https://www.arduino.cc/en/Tutorial/Button).  
```c++
// creates button on pin 12
Button* b = new Button(12);
```

**Inverted logic:**  
If you got any special kind of button that is HIGH on idle and goes to LOW when it's pressed, you can invert the logic.  
```c++
// creates inverted button on pin 12
Button* b = new Button(12, true);
```

**Pullup button:**  
This will use the internal resistor and you won't need to add an external one. Also descriped [here](https://www.arduino.cc/en/Tutorial/InputPullupSerial).  
```c++
// creates pullup button on pin 12
Button* b = new ButtonPullup(12);
```

#### On/Off Switch
You can use a switch as a button. Whenever you switch it, it will count it as a button click.  
```c++
// creates switch on pin 12
Button* b = new Switch(12);
```

#### Rotary Encoder
```c++
// creates a rotary encoder connected to pin 5 and pin 4
RotaryEncoder* rotaryEncoder = new RotaryEncoder(5, 4);

// in case you have a rotary encoder that does 2 steps with each turn (x1 encoding):
// (default is 1 step per turn)
rotaryEncoder->setSteps(2);
```

#### Analog Button
```c++
// create an analog button on pin A0 that is pushed when it reads a value between 0 and 20
ButtonAnalog* b = ButtonAnalog(A0, 0, 20);
```

#### AnalogStick
```c++
// creates an analog stick that has channelA connected to A0, channelB connected to A1 and the switch connected to pin 5
AnalogStick* analogStick = new AnalogStick(A0, A1, 5);

// set the logic to read values from 0 to 1024 with 25% tolerance
analogStick->setLogic(1024, 25);

// set the logic to read values from 0 to 256 with 25% tolerance
analogStick->setLogic(256, 25);
```

#### PlayStation2 Gamepad
```c++
// create the gamepad
PS2Gamepad* gamepad = new PS2Gamepad();

// connect to it
gamepad->setup(CLOCK_PIN, COMMAND_PIN, ATTENTION_PIN, DATA_PIN);

// check for errros
bool isConnected = gamepad->connected();
String errorMessage = gamepad->getError();
```

#### Using the PCF8574 and PCF8575
```c++
// create a PCF8574 or PCF8575
// 0x20 = i2c address (use a i2c scanner sketch to find the right address)
Wire.begin();
PCF857x* myPCF = new PCF8574(0x20);

// creates a push button connected to the PCF on pin 0
Button* b = new ButtonPCF(myPCF, 0);

// creates a pullup button connected to the PCF on pin 1
Button* b = new ButtonPullupPCF(myPCF, 1);

// rotary encoder connected to the PCF on pin 2 and pin 3
RotaryEncoder* rotaryEncoder = new RotaryEncoder(myPCF, 2, 3);

// check for errors
bool isConnected = myPCF->connected();
String errorMessage = myPCF->getError();
```

### Read out the events
`b` is a pointer to a created button (see above).  

```c++
// first update the button
b->update();

// react on double click
if(b->doubleClicked()){ ... }

// with minimum push time in ms (default = 40)
// if(b->doubleClicked(uint32_t minPushTime)) { ... }

// with minimum push time in a given time span in ms (default = 650)
// if(b->doubleClicked(uint32_t minPushTime, uint32_t timeSpan)) { ... }

// react on a click		
if(b->clicked()){ ...}

// with a minimum push time in ms (default = 40)
// if(b->clicked(uint32_t minPushTime)) { ... }

// if button is beeing hold
if(b->holding()){ ... }

// with custom time interval in ms (default = 250)
// if(b->holding(uint32_t interval)){ ... };

// when the button is beeing pushed
if(b->pushed()) { ... }

// when the button is released
if(b->released()) { ... }

// you can also read the button state out directly
bool currentButtonState = b->getState();
```

**Reading out the analog value:**  
```c++
uint8_t value = analogButton->getValue();
```

**Using the analog stick:**  
```c++
// read out the values
uint8_t x = analogStick->left->getValue();
uint8_t y = analogStick->up->getValue();

// access the switch button (if you added one)
if (analogStick->button->clicked()) Serial.println("clicked");

// react on any direction
if (analogStick->left->holding()) Serial.println("left holding");
if (analogStick->right->holding()) Serial.println("right holding");
if (analogStick->up->holding()) Serial.println("up holding");
if (analogStick->down->holding()) Serial.println("down holding");
```

**Using the gamepad:**  
```c++
// getting the analog-stick values
uint8_t left_x = gamepad->analogLeft->left->getValue();
uint8_t left_y = gamepad->analogLeft->up->getValue();

uint8_t right_x = gamepad->analogRight->left->getValue();
uint8_t right_y = gamepad->analogRight->up->getValue();

// d-pad
if (gamepad->up->clicked()) Serial.println("up clicked");
if (gamepad->down->holding()) Serial.println("down clicked");
if (gamepad->left->clicked()) Serial.println("left clicked");
if (gamepad->right->clicked()) Serial.println("right clicked");

// L and R Buttons
if (gamepad->l1->clicked()) Serial.println("L1 clicked");
if (gamepad->l2->clicked()) Serial.println("L2 clicked");
if (gamepad->r1->clicked()) Serial.println("R1 clicked");
if (gamepad->r2->clicked()) Serial.println("R2 clicked");

// start & select
if (gamepad->select->clicked()) Serial.println("Select clicked");
if (gamepad->start->clicked()) Serial.println("Start clicked");

// triangle, circle, cross, square
if (gamepad->square->clicked()) Serial.println("Square clicked");
if (gamepad->triangle->clicked()) Serial.println("Triangle clicked");
if (gamepad->x->clicked()) Serial.println("X clicked");
if (gamepad->circle->clicked()) Serial.println("Circle clicked");

// left analog stick
if (gamepad->analogLeft->button->clicked()) Serial.println("Stick-Left clicked");

if (gamepad->analogLeft->up->holding()) Serial.println("Stick-Left up");
if (gamepad->analogLeft->down->holding()) Serial.println("Stick-Left down");
if (gamepad->analogLeft->left->holding()) Serial.println("Stick-Left left");
if (gamepad->analogLeft->right->holding()) Serial.println("Stick-Left right");

// right analog stick
if (gamepad->analogRight->button->clicked()) Serial.println("Stick-Right clicked");

if (gamepad->analogRight->up->holding()) Serial.println("Stick-Right up");
if (gamepad->analogRight->down->holding()) Serial.println("Stick-Right down");
if (gamepad->analogRight->left->holding()) Serial.println("Stick-Right left");
if (gamepad->analogRight->right->holding()) Serial.println("Stick-Right right");
```

## License

This software is licensed under the MIT License. See the [license file](LICENSE) for details.  
