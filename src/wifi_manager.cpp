#include "wifi_manager.h"

#include <WiFi.h>


const char* SSID = "iPhone";
const char* PASSWORD = "Shivvy@123";



void connectWiFi()
{

    Serial.println("Connecting WiFi...");


    WiFi.mode(WIFI_STA);


    WiFi.disconnect();


    delay(1000);



    WiFi.begin(
        SSID,
        PASSWORD
    );


    int attempts = 0;



    while(
        WiFi.status() != WL_CONNECTED
        &&
        attempts < 30
    )
    {

        delay(500);

        Serial.print(".");

        attempts++;

    }



    if(WiFi.status() == WL_CONNECTED)
    {

        Serial.println();

        Serial.println("WiFi Connected!");

        Serial.print("IP: ");

        Serial.println(
            WiFi.localIP()
        );

    }

    else
    {

        Serial.println();

        Serial.println("WiFi Failed!");

    }

}




bool isWiFiConnected()
{

    return WiFi.status() == WL_CONNECTED;

}