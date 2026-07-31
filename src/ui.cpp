#include "ui.h"
#include "display.h"
/*
void drawHeader() {

    tft.fillRect(0, 0, 320, 30, ILI9341_BLUE);

    tft.setTextColor(ILI9341_WHITE);

    tft.setTextSize(2);

    tft.setCursor(10, 8);

    tft.print("SPORTDEX");

    tft.setCursor(255, 8);

    tft.print("WiFi");
}

void drawFooter() {

    tft.fillRect(0, 220, 320, 20, ILI9341_DARKGREY);

    tft.setCursor(10, 224);

    tft.setTextColor(ILI9341_WHITE);

    tft.setTextSize(1);

    tft.print("Refresh: 15 sec");

}

void drawMatchCard(Match match) {

    tft.fillRect(0, 30, 320, 190, ILI9341_BLACK);

    tft.setTextColor(ILI9341_GREEN);

    tft.setTextSize(2);

    tft.setCursor(20, 45);

    tft.print(match.league);

    tft.setTextColor(ILI9341_WHITE);

    tft.setCursor(20, 90);

    tft.print(match.homeTeam);

    tft.drawFastHLine(20, 115, 280, ILI9341_DARKGREY);

    tft.setCursor(250, 90);

    tft.print(match.homeScore);

    tft.setCursor(20, 130);

    tft.print(match.awayTeam);

    tft.setCursor(250, 130);

    tft.print(match.awayScore);

    tft.setTextColor(ILI9341_RED);

    tft.setCursor(20, 180);

    tft.print(match.status);

    tft.setCursor(250, 180);

    tft.print(match.minute);

    tft.print("'");

}

void drawBootScreen() {}
*/
void drawLeagueTable()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setCursor(10, 10);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.println("League Table");
}

void drawFixturesScreen()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setCursor(10, 10);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.println("Fixtures");
}