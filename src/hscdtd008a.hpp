#ifndef __HSCDTD008A__
#define __HSCDTD008A__

#include "driver/hscdtd008a_driver.h"

class HSCDTD008A {
public:
    void begin(void);
    void begin(uint8_t device_addr);
    hscdtd_status_t initialize(void);
    hscdtd_status_t start_measurement(void);
    hscdtd_status_t temperature_compensation(void);
    hscdtd_status_t offset_calibration(void);

    hscdtd_mag_t mag;

private:
    hscdtd_device_t device;
};

#endif  //__HSCDTD008A__
