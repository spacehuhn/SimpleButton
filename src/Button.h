#ifndef Button_h
#define Button_h

#include <stddef.h> // NULL

typedef struct button_config {
    unsigned int  mode : 2;
    unsigned int  pin  : 14;
    unsigned long update_interval;
    unsigned long push_time;
    unsigned long release_time;
    unsigned long time_span;
    unsigned long hold_interval;
} button_config;

typedef struct button_state {
    unsigned int  enabled        : 1;
    unsigned int  state          : 1;
    unsigned int  pushed         : 1;
    unsigned int  released       : 1;
    unsigned int  prev_released  : 1;
    unsigned int  clicked        : 1;
    unsigned int  double_clicked : 1;
    unsigned int  holding        : 1;
    unsigned int  clicks         : 16;
    unsigned long push_time;
    unsigned long release_time;
    unsigned long prev_push_time;
    unsigned long prev_release_time;
    unsigned long holding_time;
    unsigned long update_time;
} button_state;

typedef void (* button_callback)();

#define BUTTON_DEFAULT 0
#define BUTTON_INVERTED 1
#define BUTTON_PULLUP 2

class Button {
    private:
        button_callback onPushed        = NULL;
        button_callback onReleased      = NULL;
        button_callback onClicked       = NULL;
        button_callback onDoubleClicked = NULL;
        button_callback onHolding       = NULL;

    protected:
        struct button_config config;
        struct button_state  state;

    public:
        Button(unsigned int pin = 0, int mode = BUTTON_DEFAULT);

        // Getter
        virtual int read() const;

        bool enabled() const;
        bool inverted() const;

        bool pushed();
        bool released();
        bool clicked();
        bool doubleClicked();
        bool holding();

        int getClicks() const;

        button_state getState() const;
        button_config getConfig() const;

        // Setter
        virtual void begin();

        void enable();
        void disable();
        virtual void reset();

        void push();
        void release();

        void click();
        void click(unsigned int time);

        void doubleclick();

        virtual void update();
        virtual void update(int newState);

        void setPin(unsigned int pin, int mode = BUTTON_DEFAULT);
        void setInverted(int mode              = BUTTON_INVERTED);
        void setUpdateInterval(unsigned int interval);
        void setPushTime(unsigned int pushTime);
        void setReleaseTime(unsigned int releaseTime);
        void setTimeSpan(unsigned int timeSpan);
        void setHoldInterval(unsigned int holdInterval);

        void setOnPushed(button_callback onPushed);
        void setOnReleased(button_callback onReleased);
        void setOnClicked(button_callback onClicked);
        void setOnDoubleClicked(button_callback onDoubleClicked);
        void setOnHolding(button_callback onHolding);
};

#endif // ifndef Button_h