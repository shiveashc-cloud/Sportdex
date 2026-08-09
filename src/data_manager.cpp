#include "data_manager.h"


Standing leagueTable[20];

int teamCount = 0;


Match previousMatch;

Match nextMatch;



void clearData()
{
    teamCount = 0;


    previousMatch = Match();

    nextMatch = Match();


    for(int i=0;i<20;i++)
    {
        leagueTable[i] = Standing();
    }
}