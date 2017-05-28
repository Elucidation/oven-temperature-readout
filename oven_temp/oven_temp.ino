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
  // Init 7-segment display with dim brightness
  matrix.begin(0x70);
  matrix.setBrightness(1); // 0 min - 15 max
}

void loop() {
  // Read thermocouple temperature
  // double temp = thermocouple.readCelsius(); 
  double temp = thermocouple.readFarenheit();

  if (temp < 104) {
    // If under 104 farenheit / 40 celsius, display nothing
    matrix.clear();
    matrix.writeDisplay();
  } else {
    // Display temperature rounded to whole values on 7-segment display
    matrix.print(round(temp)); // don't care about tenths
    matrix.writeDisplay();
  }

  // MAX31855 also provides an internal temperature of the chip
  // if we wanted to show temperature outside the oven for example.
  // Serial.println(thermocouple.readInternal());
  delay(1000);
}
