/****************************************************************
 * Example1_Basics.ino
 * HSCDTD008A Library Demo
 * Bob Veringa
 * Original Creation Date: 2021-12-14
 *
 * Distributed as-is; no warranty is given.
 ***************************************************************/

#include <Arduino.h>
#include "hscdtd008a.hpp"


// Create an instance of the sensor.
HSCDTD008A geomag;


void setup() {
  hscdtd_status_t status;

  Serial.begin(9600);

  geomag.begin();
  // If you know the I2C address is different than in the provided
  // data sheet. Uncomment the line below, and configure the address.
  // geomag.begin(0x0F);

  // Initialize the hardware.
  status = geomag.initialize();
  if (status != HSCDTD_STAT_OK) {
    Serial.println("Failed to initialize sensor. Check wiring.");

    // Halt program here.
    while (true) { delay(1); }
  }
  // Compensate for temperature.
  geomag.temperatureCompensation();

}

void loop() {
  hscdtd_status_t status;

  // Explicitly start a reading.
  status = geomag.startMeasurement();
  // If the status is OK then we can print the result.
  if (status == HSCDTD_STAT_OK) {
    Serial.print("X: ");
    Serial.print(geomag.mag.mag_x);
    Serial.print("uT,\t");

    Serial.print("Y: ");
    Serial.print(geomag.mag.mag_y);
    Serial.print("uT,\t");

    Serial.print("Z: ");
    Serial.print(geomag.mag.mag_z);
    Serial.print("uT");

    Serial.println("");
  } else {
    // If it is not OK, then we don't print anything.
    Serial.println("Error occurred, unable to read sensor data.");
  }
  // Wait a bit before reading the next sample.
  delay(50);
}
