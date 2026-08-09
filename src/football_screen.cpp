#include "football_screen.h"

#include "display.h"



void drawFootballMenu()
{

    tft.fillScreen(ILI9341_BLACK);


    tft.setTextSize(2);


    tft.setCursor(30,40);

    tft.println("FOOTBALL");



    tft.setCursor(30,100);

    tft.println("> Fixtures");


    tft.setCursor(30,140);

    tft.println("  Table");


    tft.setCursor(30,180);

    tft.println("  Settings");

}



void drawFootballTable()
{

    tft.fillScreen(ILI9341_BLACK);


    tft.setCursor(20,40);

    tft.setTextSize(2);


    tft.println("LEAGUE TABLE");


}



void drawFootballFixtures()
{

    tft.fillScreen(ILI9341_BLACK);


    tft.setCursor(20,40);

    tft.setTextSize(2);


    tft.println("FIXTURES");


}