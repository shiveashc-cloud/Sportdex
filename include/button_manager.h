#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include <Arduino.h>

#define BTN_PREV 25
#define BTN_NEXT 26
#define BTN_SPORT 14

void initButtons();

bool previousPressed();
bool nextPressed();
bool sportPressed();

#endif