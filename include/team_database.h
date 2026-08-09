#pragma once

#include <Arduino.h>

struct Team
{
    int id;
    String name;
};

extern Team premierLeagueTeams[];
extern const int PREMIER_LEAGUE_TEAM_COUNT;