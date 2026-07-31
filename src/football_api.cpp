#include "football_api.h"

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define LEAGUE_TABLE_URL "https://www.thesportsdb.com/api/v1/json/123/lookuptable.php?l=4328&s=2025-2026"
#define PREVIOUS_MATCH_URL "https://www.thesportsdb.com/api/v1/json/123/eventslast.php?id=133619"
#define NEXT_MATCH_URL "https://www.thesportsdb.com/api/v1/json/123/eventsnext.php?id=133619"

bool getLeagueTable(Standing table[], int &count)
{
    HTTPClient http;

    Serial.println("Fetching League Table...");

    http.begin(LEAGUE_TABLE_URL);

    int code = http.GET();

    if (code != HTTP_CODE_OK)
    {
        Serial.println("League Table Failed");
        http.end();
        return false;
    }

    JsonDocument doc;

    DeserializationError error = deserializeJson(doc, http.getString());

    http.end();

    if (error)
    {
        Serial.println(error.c_str());
        return false;
    }

    JsonArray standings = doc["table"];
    
    count = min((int)standings.size(), 5);

    for (int i = 0; i < count; i++)
    {
        table[i].position = standings[i]["intRank"].as<int>();
        table[i].team = standings[i]["strTeam"].as<String>();
        table[i].points = standings[i]["intPoints"].as<int>();
    }

    Serial.println("League Table Loaded");

    return true;
}

bool getPreviousMatch(Match &match)
{
    HTTPClient http;

    Serial.println("Fetching Previous Match...");

    http.begin(PREVIOUS_MATCH_URL);

    int code = http.GET();

    if (code != HTTP_CODE_OK)
    {
        Serial.println("Previous Match Failed");
        http.end();
        return false;
    }

    JsonDocument doc;

    DeserializationError error = deserializeJson(doc, http.getString());

    http.end();

    if (error)
    {
        Serial.println(error.c_str());
        return false;
    }

    JsonObject event = doc["results"][0];

    match.league = event["strLeague"].as<String>();
    match.homeTeam = event["strHomeTeam"].as<String>();
    match.awayTeam = event["strAwayTeam"].as<String>();
    match.homeScore = event["intHomeScore"].as<int>();
    match.awayScore = event["intAwayScore"].as<int>();
    match.date = event["dateEvent"].as<String>();
    match.time = event["strTime"].as<String>();
    match.status = event["strStatus"].as<String>();

    Serial.println("Previous Match Loaded");

    return true;
}

bool getNextMatch(Match &match)
{
    HTTPClient http;

    Serial.println("Fetching Next Match...");

    http.begin(NEXT_MATCH_URL);

    int code = http.GET();

    if (code != HTTP_CODE_OK)
    {
        Serial.println("Next Match Failed");
        http.end();
        return false;
    }

    JsonDocument doc;

    DeserializationError error = deserializeJson(doc, http.getString());

    http.end();

    if (error)
    {
        Serial.println(error.c_str());
        return false;
    }

    JsonObject event = doc["events"][0];

    match.league = event["strLeague"].as<String>();
    match.homeTeam = event["strHomeTeam"].as<String>();
    match.awayTeam = event["strAwayTeam"].as<String>();
    match.date = event["dateEvent"].as<String>();
    match.time = event["strTime"].as<String>();
    match.status = event["strStatus"].as<String>();

    match.homeScore = -1;
    match.awayScore = -1;

    Serial.println("Next Match Loaded");

    return true;
}