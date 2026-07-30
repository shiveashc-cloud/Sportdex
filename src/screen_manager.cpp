#include "screen_manager.h"
#include "ui.h"
#include "models.h"

extern Match match;

void showScreen(Screen screen)
{
    switch (screen)
    {
        case HOME_SCREEN:

            // Do nothing here.
            // The Match struct has already been filled from the API in main.cpp.
            break;

        case FOOTBALL_SCREEN:

            // Same as HOME_SCREEN for now.
            // We'll add multiple football competitions later.
            break;

        case CRICKET_SCREEN:

            match.league = "IPL";
            match.homeTeam = "CSK";
            match.awayTeam = "RCB";
            match.homeScore = 186;
            match.awayScore = 172;
            match.status = "LIVE";
            match.minute = 18;

            break;

        case F1_SCREEN:

            match.league = "Formula 1";
            match.homeTeam = "Verstappen";
            match.awayTeam = "Norris";
            match.homeScore = 1;
            match.awayScore = 2;
            match.status = "Lap";
            match.minute = 42;

            break;

        case SETTINGS_SCREEN:

            match.league = "Settings";
            match.homeTeam = "";
            match.awayTeam = "";
            match.homeScore = 0;
            match.awayScore = 0;
            match.status = "";
            match.minute = 0;

            break;
    }

    drawHeader();
    drawMatchCard(match);
    drawFooter();
}