#include "ui.h"
#include "display.h"

void drawLeagueTable()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setCursor(10, 10);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.println("League Table");
}
/*
void drawLeagueTable_10()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setCursor(10, 10);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.println("League Table");
}
void drawLeagueTable_15()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setCursor(10, 10);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.println("League Table");
}
void drawLeagueTable_20()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setCursor(10, 10);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.println("League Table");
}
*/


void drawFixturesScreen()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setCursor(10, 10);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.println("Fixtures");
}