#pragma once

#include <Arduino.h>


struct Standing
{
    int position;
    String team;
    int points;
};


struct Match
{
    String league;

    String homeTeam;
    String awayTeam;

    String date;
    String time;

    String status;

    int homeScore;
    int awayScore;
};


extern Match previousMatch;
extern Match nextMatch;