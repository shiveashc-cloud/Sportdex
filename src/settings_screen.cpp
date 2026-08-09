#include "settings_screen.h"

#include "display.h"



void drawSettingsScreen()
{

    tft.fillScreen(ILI9341_BLACK);


    tft.setTextSize(2);


    tft.setCursor(20,50);


    tft.println("SETTINGS");


    tft.setCursor(20,100);


    tft.println("Choose Team");

}