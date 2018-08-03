#ifndef RotaryEncoderI2C_h
#define RotaryEncoderI2C_h

#include "Arduino.h"
#include <Wire.h>

#define ROTARY_ENCODER_I2C_ERROR 5

namespace simpleButton {
    class RotaryEncoderI2C {
        public:
            RotaryEncoderI2C();
            RotaryEncoderI2C(uint8_t i2cAddress);
            RotaryEncoderI2C(uint8_t i2cAddressdress, TwoWire* wire);

            ~RotaryEncoderI2C();

            void setup(uint8_t i2cAddress);
            void setup(uint8_t i2cAddress, TwoWire* wire);

            bool update();

            void begin();
            void reset();

            bool connected();
            String getError();

            void setConfig(uint8_t config);

            void enableInterrupt(uint8_t pin, bool pullup);
            void setLED(bool led);
            void setEncoding(uint8_t encoding);
            void setLoop(bool loop);
            void setInverted(bool inverted);

            bool interrupt();

            void setCounter(int32_t value);
            void setMin(int32_t value);
            void setMax(int32_t value);
            void setLEDA(uint8_t value);
            void setLEDB(uint8_t value);

            uint8_t readStatus();
            uint8_t readLEDA();
            uint8_t readLEDB();
            int32_t readCounter();
            int32_t readMax();
            int32_t readMin();

            bool pushed();
            bool incremented();
            bool decremented();
            bool minVal();
            bool maxVal();

        private:
            // temp variables
            uint8_t status = 0x00;
            uint8_t error  = 0;

            // i2c stuff
            uint8_t i2cAddress = 0x00;
            TwoWire* wire      = NULL;

            // config
            uint8_t interruptPin = 0;
            bool interruptEnable = false; // INTE
            bool interruptPullup = true;
            bool ledEnabled      = false; // LEDE
            bool encoding        = false; // x1 = false, x2 = true
            bool loop            = false; // WRAPE
            bool inverted        = false; // DIRE

            // internal functions
            void write(uint8_t address, uint8_t value);
            void write(uint8_t address, int32_t value);

            uint8_t read(uint8_t address);
            int32_t read32(uint8_t address);
    };
}
#endif // ifndef RotaryEncoderI2C_h