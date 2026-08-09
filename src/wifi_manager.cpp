#include "wifi_manager.h"

#include <WiFi.h>



const char* SSID="iPhone";

const char* PASSWORD="Shivvy@123";



void connectWiFi()
{

    Serial.print("Connecting WiFi");


    WiFi.begin(
        SSID,
        PASSWORD
    );


    int count=0;


    while(
    WiFi.status()!=WL_CONNECTED
    &&
    count<30
    )
    {

        delay(500);

        Serial.print(".");

        count++;

    }



    if(WiFi.status()==WL_CONNECTED)
    {

        Serial.println("\nConnected");

    }
    else
    {

        Serial.println("\nWiFi Failed");

    }

}



bool isWiFiConnected()
{

return WiFi.status()==WL_CONNECTED;

}