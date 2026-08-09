#include "wifi_manager.h"
#include <WiFi.h>

const char* SSID = "iPhone";
const char* PASSWORD = "Shivvy@123";


void connectWiFi()
{
    Serial.print("Connecting");

    WiFi.begin(SSID, PASSWORD);


    int attempts = 0;


    while(WiFi.status() != WL_CONNECTED && attempts < 40)
    {
        delay(500);
        Serial.print(".");
        attempts++;
    }


    Serial.println();


    if(WiFi.status() == WL_CONNECTED)
    {
        Serial.println("WiFi Connected!");

        Serial.print("IP: ");
        Serial.println(WiFi.localIP());
    }
    else
    {
        Serial.println("WiFi Failed!");
    }
}


bool isWiFiConnected()
{
    return WiFi.status() == WL_CONNECTED;
}