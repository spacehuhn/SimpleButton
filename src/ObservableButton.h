#ifndef ObservableButton_h
#define ObservableButton_h

#include "Button.h"

namespace simpleButton {
    class ObservableButton {
        public:
            ObservableButton(Button* button);
            ~ObservableButton();

            void update();

            /*
                        void setOnPushed(void (* onPushed)());
                        void setOnClicked(void (* onClicked)());
                        void setOnLongClicked(uint32_t time, void (* onLongClicked)());
                        void setOnHolded(uint32_t time, void (* onHold)());
             */

        private:
            Button* button = NULL;

            /*
                        uint32_t clickTime = 0;
                        uint32_t holdTime  = 0;

                        void (* onPushed)() = NULL;
                        void (* onClicked)() = NULL;
                        void (* onLongClicked)() = NULL;
                        void (* onHold)() = NULL;
             */
    };
}

#endif // ifndef ObservableButton_h