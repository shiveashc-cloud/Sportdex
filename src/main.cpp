#include <Arduino.h>


#include "display.h"
#include "wifi_manager.h"
#include "button_manager.h"
#include "screen_manager.h"
#include "data_manager.h"



void setup()
{

    Serial.begin(115200);

    Serial.println("SPORTDEX STARTING");


    // Initialize display
    initDisplay();


    // Connect WiFi
    connectWiFi();


    // Initialize buttons
    initButtons();


    // Load API data
    loadFootballData();


    // Start at home screen
    showScreen(HOME_SCREEN);

}




void loop()
{

    handleScreenInput();


    delay(50);

}