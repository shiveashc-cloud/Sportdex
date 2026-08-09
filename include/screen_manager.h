#pragma once


enum Screen
{
    HOME_SCREEN,

    FOOTBALL_SCREEN,

    FOOTBALL_TABLE,

    FOOTBALL_FIXTURES,

    SETTINGS_SCREEN
};


extern Screen currentScreen;



void showScreen(Screen screen);


void updateScreen();