# SimpleButton
A simple Arduino library to make interfacing and reacting on button events easier.

## Features

This libary supports:  
- Push buttons (with or without pullup or inverted logic)
- On/Off Switches
- Rotary Encoders
- The [Lameboy](https://hackaday.io/project/26823-lameboy-another-esp12-handheld) :D

You can not only read out the current state of the button, but also if it's:    
- pushed
- released
- clicked
- doubleclicked
- holded

It also works with buttons that are connected to a PCF8574 or PCF8575 GPIO expander!  
For that my [PCF8574](https://github.com/spacehuhn/PCF8574) library is integrated, so you don't need to install any additional library.  

## To-Do:
- Add support for [I2C Encoder](https://www.tindie.com/products/Saimon/i2c-encoder-connect-rotary-encoders-on-i2c-bus/)
- Add support for analog inputs/sensors
- Add support for MCP23017

(Currently waiting on my orders from China to add those :D)

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
Button* channelA = new RotaryEncoder(5);
Button* channelB = new RotaryEncoder(4, channelA);

// in case you have a rotary encoder that does 2 steps with each turn (x1 encoding):
// (default is 1 step per turn)
Button* channelA = new RotaryEncoder(5, NULL, 2);
Button* channelB = new RotaryEncoder(4, channelA, 2);
```

#### Using the PCF8574 and PCF8575
```c++
// create a PCF8574 or PCF8575
// 0x38 = i2c address (use a i2c scanner sketch to find the right address)
Wire.begin();
PCF857x* myPCF = new PCF8574(0x20);

// creates a push button connected to the PCF on pin 0
Button* b = new ButtonPCF( new Button() , myPCF, 0);

// rotary encoder connected to the PCF on pin 1 and pin 2
Button* channelA = new ButtonPCF(new RotaryEncoder(), myPCF, 1);
Button* channelB = new ButtonPCF(new RotaryEncoder(a), myPCF, 2);
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
if(b->holded()){ ... }

// with custom time interval in ms (default = 250)
// if(b->holded(uint32_t interval)){ ... };

// when the button is beeing pushed
if(b->pushed()) { ... }

// when the button is released
if(b->released()) { ... }

// you can also read the button state out directly
bool currentButtonState = b->getState();
```


## License

This software is licensed under the MIT License. See the [license file](LICENSE) for details.  
