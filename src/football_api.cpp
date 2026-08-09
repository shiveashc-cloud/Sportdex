#include "football_api.h"

#include <Arduino.h>


bool getLeagueTable(
    Standing table[],
    int &count
)
{

    Serial.println("Fetching League Table");


    // TEMP DATA
    // Replace with API later

    count = 5;


    table[0] = {
        1,
        "Liverpool",
        70
    };


    table[1] = {
        2,
        "Arsenal",
        65
    };


    table[2] = {
        3,
        "Chelsea",
        60
    };


    table[3] = {
        4,
        "Brighton",
        55
    };


    table[4] = {
        5,
        "Villa",
        50
    };


    return true;

}




bool getPreviousMatch(
    Match &match
)
{

    Serial.println("Fetching Previous Match");


    match.homeTeam="Brighton";

    match.awayTeam="Chelsea";

    match.homeScore=2;

    match.awayScore=1;

    match.date="2026-08-01";


    return true;

}





bool getNextMatch(
    Match &match
)
{

    Serial.println("Fetching Next Match");


    match.homeTeam="Brighton";

    match.awayTeam="Liverpool";

    match.date="2026-08-10";

    match.time="20:00";


    return true;

}