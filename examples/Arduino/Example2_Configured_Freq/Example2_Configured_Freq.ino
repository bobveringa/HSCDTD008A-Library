/****************************************************************
 * Example2_Configured_Freq.ino
 * HSCDTD008A Library Demo
 * Bob Veringa
 * Original Creation Date: 2021-12-31
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
  // Compensate for temperature.
  geomag.temperatureCompensation();

  // Set the device in the Normal State (required for reading using ODR).
  geomag.setStateNormal();

  // Configure (ODR) Output Data Rate.
  // Valid options are:
  // HSCDTD_ODR_0_5HZ (0.5Hz)
  // HSCDTD_ODR_10HZ  (10Hz)
  // HSCDTD_ODR_20HZ  (20Hz)
  // HSCDTD_ODR_100HZ (100Hz) (Does not work with this example)
  geomag.configureOutputDataRate(HSCDTD_ODR_20HZ);
}

void loop() {
  hscdtd_status_t status;

  // Check if data is ready.
  status = geomag.isDataReady();
  if (status == HSCDTD_STAT_OK) {
    // If there is data ready, retrieve it from the device.
    geomag.retrieveMagData();

    // And print the result.
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
    }
  // Wait a bit before checking again.
  delay(1);
}
