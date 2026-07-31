#include <Arduino.h>

#include "wifi_manager.h"
#include "football_api.h"
#include "display.h"
#include "button_manager.h"

Standing leagueTable[5];
int teamCount = 0;

Match previousMatch;
Match nextMatch;

int currentScreen = 0;

void drawLeagueScreen()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.setCursor(10,10);
    tft.println("SPORTDEX");

    tft.setTextSize(1);
    tft.setCursor(10,35);
    tft.println("Premier League 25/26");

    int y = 55;

    for(int i = 0; i < teamCount; i++)
    {
        tft.setCursor(10,y);
        tft.print(leagueTable[i].position);

        tft.print(". ");

        tft.print(leagueTable[i].team);

        tft.setCursor(215,y);
        tft.print(leagueTable[i].points);

        y += 25;
    }
}

void drawFixtureScreen()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);

    tft.setTextSize(2);
    tft.setCursor(10,10);
    tft.println("BRIGHTON");

    tft.setTextSize(1);

    //------------------------
    // Previous Match
    //------------------------

    tft.setCursor(10,40);
    tft.println("Previous");

    tft.setCursor(10,60);
    tft.println(previousMatch.league);

    tft.setCursor(10,75);
    tft.print(previousMatch.homeTeam);
    tft.print(" ");
    tft.print(previousMatch.homeScore);
    tft.print(" - ");
    tft.print(previousMatch.awayScore);
    tft.print(" ");
    tft.println(previousMatch.awayTeam);

    tft.setCursor(10,90);
    tft.println(previousMatch.date);

    //------------------------
    // Next Match
    //------------------------

    tft.setCursor(10,135);
    tft.println("Upcoming");

    tft.setCursor(10,155);
    tft.println(nextMatch.league);

    tft.setCursor(10,170);
    tft.print(nextMatch.homeTeam);
    tft.print(" vs ");
    tft.println(nextMatch.awayTeam);

    tft.setCursor(10,185);
    tft.println(nextMatch.date);

    tft.setCursor(10,200);
    tft.println(nextMatch.time);
}

void setup()
{
    Serial.begin(115200);

    connectWiFi();

    initDisplay();
    initButtons();

    if(!getLeagueTable(leagueTable, teamCount))
    {
        Serial.println("League table failed");
    }

    if(!getPreviousMatch(previousMatch))
    {
        Serial.println("Previous match failed");
    }

    if(!getNextMatch(nextMatch))
    {
        Serial.println("Next match failed");
    }

    drawLeagueScreen();
}

void loop()
{
    if(previousPressed())
    {
        currentScreen = 0;
        drawLeagueScreen();
        delay(250);
    }

    if(nextPressed())
    {
        currentScreen = 1;
        drawFixtureScreen();
        delay(250);
    }

    if(sportPressed())
    {
        Serial.println("Favourite");
        delay(250);
    }
}