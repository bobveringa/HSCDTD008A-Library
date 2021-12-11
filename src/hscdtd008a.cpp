#include "hscdtd008a.hpp"


void HSCDTD008A::begin(void)
{
    begin(HSCDTD_DEFAULT_ADDR);
}

void HSCDTD008A::begin(uint8_t device_addr)
{
    hscdtd_configure_virtual_device(&this->device, device_addr);
}

int8_t HSCDTD008A::initialize(void)
{
    return hscdtd_initialize(&this->device);
}

int8_t HSCDTD008A::start_mag_measurement(void)
{
    return hscdtd_measure(&this->device, &this->mag);
}

int8_t HSCDTD008A::temperature_compensation(void)
{
    return hscdtd_temperature_compensation(&this->device);
}

int8_t HSCDTD008A::offset_calibration(void)
{
    return hscdtd_offset_calibration(&this->device);
}
