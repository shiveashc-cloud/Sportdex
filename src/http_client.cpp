#include "http_client.h"
#include "config.h"

#include <WiFiClientSecure.h>
#include <HTTPClient.h>

String fetchTestData() {

    WiFiClientSecure client;
    client.setInsecure();   // For development only

    HTTPClient http;

    Serial.println("Connecting to API...");

    http.begin(client,
        "https://www.thesportsdb.com/api/v1/json/123/lookuptable.php?l=4328");

    http.addHeader("x-apisports-key", API_KEY);

    int httpCode = http.GET();

    Serial.print("HTTP Code: ");
    Serial.println(httpCode);

    if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        http.end();
        return payload;
    }

    http.end();
    return "";
}
