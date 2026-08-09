#pragma once

#include "models.h"


void loadFootballData();


Standing* getLeagueTable();


int getLeagueCount();


Match getPreviousMatch();


Match getNextMatch();



void setSelectedTeam(int id);


int getSelectedTeam();
