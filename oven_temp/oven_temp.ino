#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_MAX31855.h"

// 7-segment setup
Adafruit_7segment matrix = Adafruit_7segment();

// Thermocouple setup
// Software SPI on any three digital IO pins.
#define MAXDO   8
#define MAXCS   9
#define MAXCLK  10
// Initialize the Thermocouple
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

void setup() {
//  Serial.begin(9600);
  
  // Init 7-segment display with dim brightness
  matrix.begin(0x70);
  matrix.setBrightness(1); // 0 min - 15 max
}

void loop() {
  double temp = thermocouple.readCelsius(); // thermocouple temperature
  matrix.print(round(temp)); // don't care about tenths
  matrix.writeDisplay();

//  Serial.println(thermocouple.readInternal()); // Electronics temperature
  delay(1000);
}
