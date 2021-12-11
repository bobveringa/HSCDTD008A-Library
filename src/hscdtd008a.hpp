#ifndef __HSCDTD008A__
#define __HSCDTD008A__

#include "driver/hscdtd008a_driver.h"

class HSCDTD008A {
public:
    void begin(void);
    void begin(uint8_t device_addr);
    int8_t initialize(void);
    int8_t start_mag_measurement(void);
    int8_t temperature_compensation(void);
    int8_t offset_calibration(void);

    hscdtd_mag_t mag;

private:
    hscdtd_device_t device;
};

#endif  //__HSCDTD008A__
