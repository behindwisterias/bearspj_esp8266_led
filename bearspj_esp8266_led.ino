//#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "a26d6278464c4f0f983ce6dbf85d8d51";

int button = 0;
int bright = 0;

 
void setup()
{
  //Serial.begin(9600);
  Blynk.begin(auth, "FabCafeHida", "");
  strip.begin();
  strip.show();
  digitalWrite(PIN, LOW);

}



BLYNK_WRITE(1)
{
  int shift = param[0].asInt();
  for(int i=0; i< strip.numPixels(); i++)
  {
    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + shift) & 255));
  }
  strip.show();
}


BLYNK_WRITE(V5)
{
  button = param.asInt();
  if(button == 1){bright = 100;}
  else{bright = 0;}
  strip.setBrightness(bright);
  strip.show();
}

BLYNK_WRITE(V8)
{
  button = param.asInt();
  if(button == 1){bright = ;}
  else{bright = 15;}
  strip.setBrightness(bright);
  strip.show();
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);

   
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);


  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


void loop()
{
  Blynk.run();
}





