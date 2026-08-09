#pragma once


enum Screen {

    HOME_SCREEN,

    FOOTBALL_SCREEN,

    CRICKET_SCREEN,

    F1_SCREEN,

    SETTINGS_SCREEN

};
extern Screen currentScreen;

void showScreen(Screen screen);