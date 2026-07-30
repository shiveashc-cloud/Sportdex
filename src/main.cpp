#include <Arduino.h>

#include "wifi_manager.h"
#include "football_api.h"

#include "display.h"


Standing leagueTable[20];

int teamCount = 0;



void setup()
{

    Serial.begin(115200);


    connectWiFi();



    if(!getLeagueTable(leagueTable, teamCount))
    {
        Serial.println("Failed loading table");
        return;
    }



    initDisplay();


    tft.fillScreen(ILI9341_BLACK);


    tft.setTextColor(ILI9341_WHITE);


    tft.setTextSize(2);

    tft.setCursor(10,10);

    tft.println("SPORTDEX");



    tft.setTextSize(1);


    tft.setCursor(10,40);

    tft.println("Premier League 25/26");



    int y = 65;



    for(int i = 0; i < 5; i++)
    {

        tft.setCursor(10,y);


        tft.print(
        leagueTable[i].position
        );


        tft.print(". ");


        tft.print(
        leagueTable[i].team
        );


        tft.setCursor(220,y);


        tft.print(
        leagueTable[i].points
        );


        y += 25;

    }


}



void loop()
{

}