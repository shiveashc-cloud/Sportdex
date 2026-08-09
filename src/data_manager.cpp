#include "data_manager.h"

#include "football_api.h"



Standing leagueTable[20];

int leagueCount = 0;


Match previousMatch;

Match nextMatch;



int selectedTeam = 51;




void loadFootballData()
{

    Serial.println("Loading Football Data");


    if(!getLeagueTable(
        leagueTable,
        leagueCount))
    {
        Serial.println("Table failed");
    }


    if(!getPreviousMatch(previousMatch))
    {
        Serial.println("Previous failed");
    }


    if(!getNextMatch(nextMatch))
    {
        Serial.println("Next failed");
    }

}




Standing* getLeagueTable()
{
    return leagueTable;
}



int getLeagueCount()
{
    return leagueCount;
}



Match getPreviousMatch()
{
    return previousMatch;
}



Match getNextMatch()
{
    return nextMatch;
}




void setSelectedTeam(int id)
{
    selectedTeam=id;
}



int getSelectedTeam()
{
    return selectedTeam;
}