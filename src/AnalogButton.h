#ifndef AnalogButton_h
#define AnalogButton_h

#include "Button.h"

class AnalogButton : public Button {
    private:
        int minValue;
        int maxValue;
        int value;

    protected:
    public:
        AnalogButton(int pin = -1, int minValue = 0, int maxValue = 1024);

        // getter
        int read() const override;

        int getMin() const;
        int getMax() const;
        int getValue() const;

        // setter
        void update() override;
        void update(int value) override;

        void setMin(int minValue);
        void setMax(int maxValue);
};

#endif // ifndef AnalogButton_h