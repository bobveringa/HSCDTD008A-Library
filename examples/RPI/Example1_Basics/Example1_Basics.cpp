/****************************************************************
 * Example1_Basics.cpp
 * HSCDTD008A Library Demo
 * Tilman Glötzner
 * Original Creation Date: 2022-09-03
 * Heavily based on the code of Bob Veringa
 *
 * Distributed as-is; no warranty is given.
 ***************************************************************/

#include "hscdtd008a.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

// Create an instance of the sensor.
HSCDTD008A geomag;


void setup() {
  hscdtd_status_t status;
  
  geomag.begin();
  // If you know the I2C address is different than in the provided
  // data sheet. Uncomment the line below, and configure the address.
  geomag.begin(0x0F);

  // Initialize the hardware.
  status = geomag.initialize();
  if (status != HSCDTD_STAT_OK) {
    printf("Failed to initialize sensor. Status:%d. Check wiring.\n", status);

    // Halt program here.
    exit(1);
  }
  // Compensate for temperature.
  geomag.temperatureCompensation();

}

void loop() {
  hscdtd_status_t status;
  float bAbs;

  // Explicitly start a reading.
  status = geomag.startMeasurement();
  // If the status is OK then we can print the result.
  if (status == HSCDTD_STAT_OK) {
    bAbs = sqrt(pow(geomag.mag.mag_x, 2) + 
		pow(geomag.mag.mag_y, 2) + 
		pow(geomag.mag.mag_z, 2));
    printf("X: %f uT,\tY: %f uT,\tZ: %f uT;\t|B|: %f uT\n", 
    	geomag.mag.mag_x, geomag.mag.mag_y, geomag.mag.mag_z, bAbs);
  } else {
    printf("Error occurred, unable to read sensor data. Exiting ...\n");
    exit(1);
  }
  // Wait 50ms  before reading the next sample.
  usleep(50000);
}

int main(int argc, char** argv)
{
   setup(); 
   loop();
}

