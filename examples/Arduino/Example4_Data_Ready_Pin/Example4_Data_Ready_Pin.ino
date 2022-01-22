/****************************************************************
 * Example4_Data_Ready_Pin.ino
 * HSCDTD008A Library Demo
 * Bob Veringa
 * Original Creation Date: 2021-01-16
 *
 * Distributed as-is; no warranty is given.
 ***************************************************************/

#include <Arduino.h>
#include "hscdtd008a.h"


// The pin DRDY is connected to on the Arduino.
// It is required to connect a pull down resistor (between 1k and 4k) to this line.
const int data_ready_pin = 2;

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

  // Enable data ready pin output.
  geomag.setDataReadyPinEnabledStatus(HSCDTD_DEN_ENABLED);
}


void loop() {
  int status;

  // Make sure a pull down resistor (between 1k and 4k) is connected to the data ready line.
  // Check if data is ready by digital read.
  status = digitalRead(data_ready_pin);

  if (status == HIGH) {
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
  delay(5);
}
