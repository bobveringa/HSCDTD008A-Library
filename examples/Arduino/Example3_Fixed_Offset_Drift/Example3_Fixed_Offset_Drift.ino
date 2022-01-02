/****************************************************************
 * Example3_Fixed_Offset_Drift.ino
 * HSCDTD008A Library Demo
 * Bob Veringa
 * Original Creation Date: 2022-01-02
 *
 * Distributed as-is; no warranty is given.
 ***************************************************************/

#include <Arduino.h>
#include "hscdtd008a.h"


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

  // Calibrate standard offset (Bases all values around 0, instead of absolute)
  geomag.offsetCalibration();

  // Apply a fixed offset
  status = geomag.applyOffsetDrift(-100, 500, 1200);

  // Because we did offset calibration, printed values should be around these
  // offset value (if there are no changes in magnetic field).
  if (status != HSCDTD_STAT_OK) {
    Serial.println("Failed to apply offset");
  }

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
    Serial.println(status);
    // If it is not OK, then we don't print anything.
    Serial.println("Error occurred, unable to read sensor data.");
  }
  // Wait a bit before reading the next sample.
  delay(50);
}
