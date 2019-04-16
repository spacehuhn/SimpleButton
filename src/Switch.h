#ifndef Switch_h
#define Switch_h

#include <stddef.h> // NULL

typedef struct switch_config {
    int           pin  : 14;
    unsigned int  mode : 2;
    unsigned long update_interval;
    unsigned long switch_delay;
} switch_config;

typedef struct switch_state {
    unsigned int  enabled      : 1;
    unsigned int  state        : 1;
    unsigned int  prev_state   : 1;
    unsigned int  pushed       : 1;
    unsigned int  released     : 1;
    unsigned int  switched     : 1;
    unsigned int  switched_on  : 1;
    unsigned int  switched_off : 1;
    unsigned int  switches     : 16;
    unsigned long switch_time;
    unsigned long update_time;
} switch_state;

typedef void (* switch_callback)();

#define SWITCH_DEFAULT 0
#define SWITCH_INVERTED 1
#define SWITCH_PULLUP 2

class Switch {
    private:
        switch_config config;
        switch_state state;

        switch_callback onPushed      = NULL;
        switch_callback onReleased    = NULL;
        switch_callback onSwitched    = NULL;
        switch_callback onSwitchedOn  = NULL;
        switch_callback onSwitchedOff = NULL;

    protected:
    public:
        Switch(int pin, int mode = SWITCH_DEFAULT);

        // Getter
        int read() const;

        bool enabled() const;
        bool inverted() const;

        bool pushed();
        bool released();
        bool switched();
        bool switchedOn();
        bool switchedOff();

        int getSwitches() const;

        switch_state getState() const;
        switch_config getConfig() const;

        // Setter
        void begin();

        void enable();
        void disable();
        void reset();

        void push();
        void release();

        void switch_();
        void switchOn();
        void switchOff();

        void update();
        void update(int newState);

        void setX(int xVal);
        void setY(int yVal);

        void setPin(int pin, int mode = SWITCH_DEFAULT);
        void setInverted(int mode     = SWITCH_INVERTED);
        void setUpdateInterval(unsigned int interval);
        void setSwitchDelay(unsigned int switchDelay);

        void setOnPushed(switch_callback onPushed);
        void setOnReleased(switch_callback onReleased);
        void setOnSwitched(switch_callback onSwitched);
        void setOnSwitchedOn(switch_callback onSwitchedOn);
        void setOnSwitchedOff(switch_callback onSwitchedOff);
};

#endif // ifndef Switch_h