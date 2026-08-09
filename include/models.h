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

    int homeScore;
    int awayScore;

    String date;
    String time;
};


struct Team
{
    String name;
    int id;
};