#include "ObservableButton.h"

namespace simpleButton {
    ObservableButton::ObservableButton(Button* button) {
        ObservableButton::button = button;
    }

    ObservableButton::~ObservableButton() {
        if (button) delete button;
    }

    /*
       void ObservableButton::setOnPushed(void (*onPushed)()) {
       ObservableButton::onPushed = onPushed;
       }

       void ObservableButton::setOnClicked(void (*onClicked)()) {
       ObservableButton::onClicked = onClicked;
       }

       void ObservableButton::setOnLongClicked(uint32_t time, void (*onLongClicked)()) {
       ObservableButton::clickTime = time;
       ObservableButton::onLongClicked = onLongClicked;
       }

       void ObservableButton::setOnHolded(uint32_t time, void (*onHold)()) {
       ObservableButton::holdTime = time;
       ObservableButton::onHold = onHold;
       }*/
    void ObservableButton::update() {
        /*
           button->update();

           if (onHold && button->holded(holdTime)) onHold();
           if (onLongClicked && button->clicked(clickTime)) onLongClicked();
           if (onClicked && button->clicked()) onClicked();
           if (onPushed && button->pushed()) onPushed();
         */
    }
}