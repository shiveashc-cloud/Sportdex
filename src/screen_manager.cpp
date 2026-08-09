#include "screen_manager.h"

#include "home_screen.h"
#include "football_screen.h"
#include "settings_screen.h"

#include "button_manager.h"



Screen currentScreen = HOME_SCREEN;


int menuIndex = 0;



void showScreen(Screen screen)
{

    currentScreen = screen;

    menuIndex = 0;

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





void handleScreenInput()
{


    if(previousPressed())
    {

        menuIndex--;


        if(menuIndex < 0)
            menuIndex = 0;


        updateScreen();

    }



    if(nextPressed())
    {

        menuIndex++;


        updateScreen();

    }





    if(selectPressed())
    {


        switch(currentScreen)
        {


            case HOME_SCREEN:

                showScreen(FOOTBALL_MENU);

                break;



            case FOOTBALL_MENU:


                if(menuIndex == 0)
                {
                    showScreen(FOOTBALL_FIXTURES);
                }


                else if(menuIndex == 1)
                {
                    showScreen(FOOTBALL_TABLE);
                }


                else if(menuIndex == 2)
                {
                    showScreen(SETTINGS_SCREEN);
                }


                break;




            case SETTINGS_SCREEN:

                // later:
                // save selected team

                break;




            default:

                break;


        }

    }

}