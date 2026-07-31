#include "button_manager.h"

void initButtons()
{
    pinMode(BTN_PREV, INPUT_PULLUP);
    pinMode(BTN_NEXT, INPUT_PULLUP);
    pinMode(BTN_SPORT, INPUT_PULLUP);
}

bool previousPressed()
{
    return digitalRead(BTN_PREV) == LOW;
}

bool nextPressed()
{
    return digitalRead(BTN_NEXT) == LOW;
}

bool sportPressed()
{
    return digitalRead(BTN_SPORT) == LOW;
}
