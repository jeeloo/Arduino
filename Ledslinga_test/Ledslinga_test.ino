#include "SPI.h"
#include "Adafruit_WS2801.h"

  uint8_t dataPin  = 19;    //Analog 3 (Analog pins used to simplify wiring. By using Analog pins we only need to have wires on one side of the Arduino Nano
  uint8_t clockPin = 17;    // Analog 5

  // Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
  Adafruit_WS2801 strip = Adafruit_WS2801(100, dataPin, clockPin);

void setup() {
  // put your setup code here, to run once: 
  strip.begin();
 
  // Update LED contents, to start they are all 'off'
  strip.show();
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
 
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
 
/* Helper functions */
// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}
void loop() {
  // put your main code here, to run repeatedly:
  colorWipe(Color(255, 0, 0), 150);  // red fill
  colorWipe(Color(0, 255, 0), 150);  // green fill
  colorWipe(Color(0, 0, 255), 150);  // blue fill
}
