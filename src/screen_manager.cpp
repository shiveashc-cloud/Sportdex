#include "screen_manager.h"
#include "ui.h"

void showScreen(Screen screen)
{
    switch (screen)
    {
        case HOME_SCREEN:
            drawLeagueTable();
            break;

        case FOOTBALL_SCREEN:
            drawFixturesScreen();
            break;

        default:
            drawLeagueTable();
            break;
    }
}