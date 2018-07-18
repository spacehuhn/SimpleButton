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

## Usage

*Coming soon* :P
In the meantime, look at the [examples](https://github.com/spacehuhn/SimpleButton/tree/master/examples).  

## License 

This software is licensed under the MIT License. See the [license file](LICENSE) for details.  
