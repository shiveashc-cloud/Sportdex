#include <Arduino.h>


#include "display.h"

#include "wifi_manager.h"

#include "button_manager.h"

#include "screen_manager.h"

#include "data_manager.h"




void setup()
{

    Serial.begin(115200);



    Serial.println("SPORTDEX STARTING");



    clearData();


    initDisplay();


    connectWiFi();



    initButtons();



    showScreen(HOME_SCREEN);

}





void loop()
{


    if(nextPressed())
    {

        menuIndex++;


        if(menuIndex > 2)
            menuIndex = 0;



        updateScreen();

    }





    if(previousPressed())
    {


        if(currentScreen != HOME_SCREEN)
        {

            showScreen(HOME_SCREEN);

        }

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
                    showScreen(FOOTBALL_FIXTURES);


                else if(menuIndex == 1)
                    showScreen(FOOTBALL_TABLE);



                else if(menuIndex == 2)
                    showScreen(SETTINGS_SCREEN);


                break;



            default:

                showScreen(FOOTBALL_MENU);

                break;


        }


    }



    delay(50);

}