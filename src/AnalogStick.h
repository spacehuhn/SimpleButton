#ifndef AnalogStick_h
#define AnalogStick_h

#include "Button.h"
#include "AnalogButton.h"

typedef void (* analogstick_callback)(int x, int y, bool pushed);

class AnalogStick {
    private:
        analogstick_callback callback = NULL;

    protected:
    public:
        AnalogButton up;
        AnalogButton down;
        AnalogButton left;
        AnalogButton right;
        Button select;

        AnalogStick(int xPin = -1, int yPin = -1, int selectPin = -1);
        AnalogStick(AnalogButton up, AnalogButton down, AnalogButton left, AnalogButton right, Button select);

        // Getter
        int readX() const;
        int readY() const;
        int readSelect() const;

        // Setter
        void begin();

        void enable();
        void disable();
        void reset();

        void update();

        void setX(int xVal);
        void setY(int yVal);

        void setPin(int xPin = -1, int yPin = -1, int selectPin = -1);
        void setUpdateInterval(unsigned int interval);
        void setPushTime(unsigned int pushTime);
        void setReleaseTime(unsigned int releaseTime);
        void setTimeSpan(unsigned int timeSpan);
        void setHoldInterval(unsigned int holdInterval);

        void setCallback(analogstick_callback callback);
};

#endif /* ifndef AnalogStick_h */