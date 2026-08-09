#pragma once


enum Screen
{

    HOME_SCREEN,

    FOOTBALL_MENU,

    FOOTBALL_TABLE,

    FOOTBALL_FIXTURES,

    SETTINGS_SCREEN

};



extern Screen currentScreen;


extern int menuIndex;



void showScreen(Screen screen);


void updateScreen();


void handleScreenInput();