#include "hscdtd008a.hpp"


/**
 * @brief Standard enable function for object.
 *
 */
void HSCDTD008A::begin(void)
{
    begin(HSCDTD_DEFAULT_ADDR);
}

/**
 * @brief Additional enable function in case I2C address is different
 * than the default.
 *
 * @param device_addr I2C address.
 */
void HSCDTD008A::begin(uint8_t device_addr)
{
    hscdtd_configure_virtual_device(&this->device, device_addr);
}


/**
 * @brief Initialize the device.
 *
 * @return hscdtd_status_t.
 */
hscdtd_status_t HSCDTD008A::initialize(void)
{
    return hscdtd_initialize(&this->device);
}


/**
 * @brief Start a measurement of the magneto reader.
 *
 * @return hscdtd_status_t.
 */
hscdtd_status_t HSCDTD008A::start_mag_measurement(void)
{
    return hscdtd_measure(&this->device, &this->mag);
}


/**
 * @brief Run temperature compenstation.
 *
 * This uses the built-in device function to compensate reading results
 * with the current temperature.
 *
 * @return hscdtd_status_t.
 */
hscdtd_status_t HSCDTD008A::temperature_compensation(void)
{
    return hscdtd_temperature_compensation(&this->device);
}


/**
 * @brief Run offset calibration.
 *
 * This uses the built-in device function to calibrate the internal ADC.
 *
 * @return hscdtd_status_t.
 */
hscdtd_status_t HSCDTD008A::offset_calibration(void)
{
    return hscdtd_offset_calibration(&this->device);
}
