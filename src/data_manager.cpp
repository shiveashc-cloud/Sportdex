#include "data_manager.h"
#include "football_api.h"


extern Standing leagueTable[20];

extern int teamCount = 0;


extern Match previousMatch;
extern Match nextMatch;



void loadSportsData()
{

    getLeagueTable(
        leagueTable,
        teamCount
    );


    getPreviousMatch(
        previousMatch
    );


    getNextMatch(
        nextMatch
    );

}