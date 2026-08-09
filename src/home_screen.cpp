#include "home_screen.h"

#include "display.h"



void drawHomeScreen()
{

    tft.fillScreen(ILI9341_BLACK);


    tft.setTextSize(3);

    tft.setCursor(40,40);

    tft.println("SPORTDEX");



    tft.setTextSize(2);


    tft.setCursor(50,100);

    tft.println("> FOOTBALL");



    tft.setCursor(50,140);

    tft.println("  CRICKET");



    tft.setCursor(50,180);

    tft.println("  TENNIS");


}