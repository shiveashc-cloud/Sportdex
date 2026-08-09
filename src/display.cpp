#include "display.h"

#include "config.h"



Adafruit_ILI9341 tft(
TFT_CS,
TFT_DC,
TFT_RST
);



void initDisplay()
{

    tft.begin();


    tft.setRotation(1);


    tft.fillScreen(ILI9341_BLACK);


    tft.setTextColor(ILI9341_WHITE);

}