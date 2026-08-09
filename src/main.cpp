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


clearData();


initDisplay();


connectWiFi();


initButtons();


showScreen(HOME_SCREEN);


}



void loop()
{

handleButtons();


delay(50);

}