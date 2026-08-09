#include <Arduino.h>

#include "wifi_manager.h"
#include "football_api.h"
#include "display.h"
#include "button_manager.h"
#include "models.h"
#include "data_manager.h"
#include "screen_manager.h"


// ===============================
// League Table Screen
// ===============================

void drawLeagueScreen()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);

    tft.setTextSize(2);
    tft.setCursor(10,10);
    tft.println("SPORTDEX");


    tft.setTextSize(1);
    tft.setCursor(10,35);
    tft.println("Premier League 26/27");


    int y = 60;


    for(int i = 0; i < 10 && i < teamCount; i++)
    {
        tft.setCursor(10,y);

        tft.print(leagueTable[i].position);
        tft.print(". ");

        tft.print(leagueTable[i].team);


        tft.setCursor(220,y);

        tft.print(leagueTable[i].points);


        y += 25;
    }
}



// ===============================
// Brighton Fixtures Screen
// ===============================

void drawFixtureScreen()
{
    tft.fillScreen(ILI9341_BLACK);


    tft.setTextColor(ILI9341_WHITE);


    tft.setTextSize(2);
    tft.setCursor(10,10);

    tft.println("BRIGHTON");


    tft.setTextSize(1);



    // Previous match

    tft.setCursor(10,45);
    tft.println("Previous Match");


    tft.setCursor(10,65);
    tft.println(previousMatch.league);


    tft.setCursor(10,85);

    tft.print(previousMatch.homeTeam);
    tft.print(" ");

    tft.print(previousMatch.homeScore);

    tft.print(" - ");

    tft.print(previousMatch.awayScore);

    tft.print(" ");

    tft.println(previousMatch.awayTeam);



    tft.setCursor(10,105);

    tft.println(previousMatch.date);



    // Next match


    tft.setCursor(10,145);

    tft.println("Upcoming Match");



    tft.setCursor(10,165);

    tft.println(nextMatch.league);



    tft.setCursor(10,185);

    tft.print(nextMatch.homeTeam);

    tft.print(" vs ");

    tft.println(nextMatch.awayTeam);



    tft.setCursor(10,205);

    tft.println(nextMatch.date);



    tft.setCursor(10,220);

    tft.println(nextMatch.time);

}




// ===============================
// Setup
// ===============================

void setup()
{

    Serial.begin(115200);


    Serial.println("SPORTDEX STARTING");



    // Start display first

    initDisplay();

    initButtons();



    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);

    tft.setCursor(10,10);

    tft.setTextSize(2);

    tft.println("Loading...");



    // Connect WiFi

    connectWiFi();



    // Fetch data


    if(!getLeagueTable(leagueTable, teamCount))
    {
        Serial.println("League table failed");
    }
    else
    {
        Serial.println("League table loaded");
    }



    if(!getPreviousMatch(previousMatch))
    {
        Serial.println("Previous match failed");
    }
    else
    {
        Serial.println("Previous match loaded");
    }



    if(!getNextMatch(nextMatch))
    {
        Serial.println("Next match failed");
    }
    else
    {
        Serial.println("Next match loaded");
    }



    // Default screen

    currentScreen = 0;

    drawLeagueScreen();

}





// ===============================
// Loop
// ===============================

void loop()
{


    if(previousPressed())
    {

        currentScreen = 0;

        drawLeagueScreen();

        Serial.println("League Screen");

        delay(250);

    }



    if(nextPressed())
    {

        currentScreen = 1;

        drawFixtureScreen();

        Serial.println("Fixture Screen");

        delay(250);

    }



    if(sportPressed())
    {

        Serial.println("Sport Button Pressed");

        delay(250);

    }


}