/*-------------------------------------------------------------------------
  Spark Core library to control WS2801 based RGB
  LED devices such as Adafruit led pixels.
  
  Written by Adafruit - MIT license.
  Modified to work with Spark Core by Technobly.
  Modified to work with WS2801_BRG LED by OliverMartini.  
  Contributions by other members of the open source community.
  
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing products
  from Adafruit!
  --------------------------------------------------------------------*/

/* ========================== Adafruit_WS2801.h =========================== */
 
#ifndef __ADAFRUIT_WS2801__
#define __ADAFRUIT_WS2801__

// Make library cross-compatiable
// with Arduino, GNU C++ for tests, and Spark.
//#if defined(ARDUINO) && ARDUINO >= 100
//#include "Arduino.h"
//#elif defined(SPARK)
//#include "application.h"
//#endif

// TEMPORARY UNTIL the stuff that supports the code above is deployed to the build IDE
#include "application.h"

// Not all LED pixels are RGB order; 36mm type expects GRB data.
// Optional flag to constructors indicates data order (default if
// unspecified is RGB).  As long as setPixelColor/getPixelColor are
// used, other code can always treat 'packed' colors as RGB; the
// library will handle any required translation internally.
#define WS2801_RGB 0
#define WS2801_GRB 1
#define WS2801_BRG 2
 
#define boolean bool
 
class Adafruit_WS2801 {
 
 public:
 
  // Configurable pins:
  Adafruit_WS2801(uint16_t n, uint8_t dpin, uint8_t cpin, uint8_t order=WS2801_RGB);
  Adafruit_WS2801(uint16_t x, uint16_t y, uint8_t dpin, uint8_t cpin, uint8_t order=WS2801_RGB);
  // Use SPI hardware; specific pins only:
  Adafruit_WS2801(uint16_t n, uint8_t order=WS2801_RGB);
  // Empty constructor; init pins/strand length/data order later:
  Adafruit_WS2801();
  // Release memory (as needed):
  ~Adafruit_WS2801();
 
  void
    begin(void),
    show(void),
    setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t n, uint32_t c),
    setPixelColor(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t x, uint16_t y, uint32_t c),
    updatePins(uint8_t dpin, uint8_t cpin), // Change pins, configurable
    updatePins(void), // Change pins, hardware SPI
    updateLength(uint16_t n), // Change strand length
    updateOrder(uint8_t order); // Change data order
  uint16_t
    numPixels(void);
  uint32_t
    getPixelColor(uint16_t n);
 
 private:
 
  uint16_t
    numLEDs,
    width,     // used with matrix mode
    height;    // used with matrix mode
  uint8_t
    *pixels,   // Holds color values for each LED (3 bytes each)
    rgb_order, // Color order; RGB vs GRB (or others, if needed in future)
    clkpin    , datapin,     // Clock & data pin numbers
    clkpinmask, datapinmask; // Clock & data PORT bitmasks
  volatile uint8_t
    *clkport  , *dataport;   // Clock & data PORT registers
  void
    alloc(uint16_t n),
    startSPI(void);
  boolean
    hardwareSPI, // If 'true', using hardware SPI
    begun;       // If 'true', begin() method was previously invoked
};

#endif // __ADAFRUIT_WS2801__