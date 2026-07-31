#pragma once

#include <Arduino.h>

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

struct Standing
{
    int position;

    String team;

    int points;
};