#include "button_manager.h"

#include "config.h"

#include <Arduino.h>



bool previousState = HIGH;

bool nextState = HIGH;

bool selectState = HIGH;




void initButtons()
{

    pinMode(
        BUTTON_PREVIOUS,
        INPUT_PULLUP
    );


    pinMode(
        BUTTON_NEXT,
        INPUT_PULLUP
    );


    pinMode(
        BUTTON_SELECT,
        INPUT_PULLUP
    );

}




bool previousPressed()
{

    bool state = digitalRead(BUTTON_PREVIOUS);



    if(state == LOW && previousState == HIGH)
    {

        delay(30);

        previousState = state;

        return true;

    }


    previousState = state;


    return false;

}




bool nextPressed()
{

    bool state = digitalRead(BUTTON_NEXT);



    if(state == LOW && nextState == HIGH)
    {

        delay(30);

        nextState = state;

        return true;

    }


    nextState = state;


    return false;

}




bool selectPressed()
{

    bool state = digitalRead(BUTTON_SELECT);



    if(state == LOW && selectState == HIGH)
    {

        delay(30);

        selectState = state;

        return true;

    }


    selectState = state;


    return false;

}




void handleButtons()
{

}