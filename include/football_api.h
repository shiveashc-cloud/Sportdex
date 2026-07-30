#ifndef FOOTBALL_API_H
#define FOOTBALL_API_H

#include <Arduino.h>


struct Standing
{
    int position;

    String team;

    int played;
    int wins;
    int draws;
    int losses;

    int goalDifference;

    int points;
};


bool getLeagueTable(Standing table[], int &count);


#endif