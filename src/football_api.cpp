#include "football_api.h"

#include <ArduinoJson.h>

#include "http_client.h"



bool getLeagueTable(Standing table[], int &count)
{

    String json = fetchTestData();


    JsonDocument doc;


    DeserializationError error =
    deserializeJson(doc, json);



    if(error)
    {
        Serial.print("JSON Error: ");
        Serial.println(error.c_str());

        return false;
    }



    JsonArray teams = doc["table"];



    if(teams.isNull())
    {
        Serial.println("Table missing");

        return false;
    }



    count = 0;



    for(JsonObject team : teams)
    {

        if(count >= 20)
            break;



        table[count].position =
        team["intRank"]
        .as<String>()
        .toInt();



        table[count].team =
        team["strTeam"]
        .as<String>();


        table[count].played =
        team["intPlayed"]
        .as<String>()
        .toInt();


        table[count].wins =
        team["intWin"]
        .as<String>()
        .toInt();


        table[count].draws =
        team["intDraw"]
        .as<String>()
        .toInt();


        table[count].losses =
        team["intLoss"]
        .as<String>()
        .toInt();


        table[count].goalDifference =
        team["intGoalDifference"]
        .as<String>()
        .toInt();


        table[count].points =
        team["intPoints"]
        .as<String>()
        .toInt();



        count++;

    }


    return true;
}