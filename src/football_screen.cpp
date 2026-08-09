#include "football_screen.h"

#include "display.h"

#include "screen_manager.h"



void drawFootballMenu()
{

    tft.fillScreen(ILI9341_BLACK);


    tft.setTextSize(2);


    tft.setCursor(30,40);

    tft.println("FOOTBALL");



    tft.setCursor(30,100);


    if(menuIndex==0)
        tft.print("> ");
    else
        tft.print("  ");

    tft.println("Fixtures");




    tft.setCursor(30,140);


    if(menuIndex==1)
        tft.print("> ");
    else
        tft.print("  ");


    tft.println("Table");




    tft.setCursor(30,180);


    if(menuIndex==2)
        tft.print("> ");
    else
        tft.print("  ");


    tft.println("Settings");


}





void drawFootballTable()
{

    tft.fillScreen(ILI9341_BLACK);


    tft.setCursor(20,40);

    tft.setTextSize(2);

    tft.println("TABLE");

}



void drawFootballFixtures()
{

    tft.fillScreen(ILI9341_BLACK);


    tft.setCursor(20,40);

    tft.setTextSize(2);

    tft.println("FIXTURES");

}