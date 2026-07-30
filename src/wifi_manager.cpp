#include "wifi_manager.h"
#include <WiFi.h>

const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";

void connectWiFi()
{
    Serial.print("Connecting");

    WiFi.begin(SSID, PASSWORD, 6);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(250);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}

bool isWiFiConnected()
{
    return WiFi.status() == WL_CONNECTED;
}