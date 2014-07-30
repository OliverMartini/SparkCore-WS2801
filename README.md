SparkCore-WS2801
================
An example library for driving Adafruit WS2801 pixels for the Spark Core.
Implementation based on Adafruit's WS2801 Library.

  Designed specifically to work with the Adafruit RGB Pixels!
  12mm Bullet shape ----> https://www.adafruit.com/products/322
  12mm Flat shape   ----> https://www.adafruit.com/products/738
  36mm Square shape ----> https://www.adafruit.com/products/683

  These pixels use SPI to transmit the color data, and have built in
  high speed PWM drivers for 24 bit color per pixel
  2 pins are required to interface

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

Components Required
---

- WS2801 digital RGB LED (get at [adafruit.com](adafruit.com))

Example Usage
---

See this [example](firmware/examples/ws2801-example.cpp) for details, or, in a nutshell:

```cpp
Adafruit_WS2801 strip = Adafruit_WS2801(9, WS2801_BRG);
void setup() {
  strip.begin();
  strip.show();
}
void loop() {
  // change your pixel colors and call strip.show() again
}
```

Nuances
---

- Make sure get the # of pixels, pin number, type of pixels correct
- Besides WS2801_RGB, WS2801_GRB this library also supports WS2801_BRG pixels.


Useful Links
---

- WS2801 Guide: https://learn.adafruit.com/12mm-led-pixels/code