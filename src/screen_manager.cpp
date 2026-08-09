#include "screen_manager.h"


#include "home_screen.h"

#include "football_screen.h"

#include "settings_screen.h"



Screen currentScreen = HOME_SCREEN;


int menuIndex = 0;




void showScreen(Screen screen)
{

    currentScreen = screen;


    updateScreen();

}




void updateScreen()
{

    switch(currentScreen)
    {


        case HOME_SCREEN:

            drawHomeScreen();

            break;



        case FOOTBALL_MENU:

            drawFootballMenu();

            break;



        case FOOTBALL_TABLE:

            drawFootballTable();

            break;



        case FOOTBALL_FIXTURES:

            drawFootballFixtures();

            break;



        case SETTINGS_SCREEN:

            drawSettingsScreen();

            break;


    }

}