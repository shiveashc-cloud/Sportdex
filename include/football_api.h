#ifndef FOOTBALL_API_H
#define FOOTBALL_API_H

#include "models.h"

bool getLeagueTable(Standing table[], int &count);

bool getPreviousMatch(Match &match);

bool getNextMatch(Match &match);

#endif