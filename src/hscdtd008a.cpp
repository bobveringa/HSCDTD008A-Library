#include "hscdtd008a.h"


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
 * @brief Init the transportation cookie
 * @param device_addr I2C address.
 */
hscdtd_status_t HSCDTD008A::initialize_transport(platform_cookie_t *cookie)
{
    return hscdtd_initialize_transport(&this->device, cookie);
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
hscdtd_status_t HSCDTD008A::startMeasurement(void)
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
hscdtd_status_t HSCDTD008A::temperatureCompensation(void)
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
hscdtd_status_t HSCDTD008A::offsetCalibration(void)
{
    return hscdtd_offset_calibration(&this->device);
}


/**
 * @brief Run a self test
 *
 * Run a self test to verify that the internals of the chp are working properly.
 *
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::runSelfTest(void)
{
    return hscdtd_self_test(&this->device);
}


/**
 * @brief Soft reset the chip
 *
 * Soft resetting the chip re-initializes all the regsiter values to their
 * default values.
 *
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::softReset(void)
{
    return hscdtd_soft_reset(&this->device);
}


/**
 * @brief Put the chip in stand-by mode
 *
 * Putting the chip in stand-by mode significantly reduces the energy usage
 * of the device. Register reading and writing is still possible.
 *
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::setStandby(void)
{
    return hscdtd_set_mode(&this->device, HSCDTD_MODE_STANDBY);
}


/**
 * @brief Put the chip in active mode
 *
 * Putting the chip in active mode is required for chip operations such as:
 *  1. Reading Sensor Data
 *  2. Performing Offset Calibration
 *  3. Performing Temperature Compenstation
 *
 * Chip uses more power in active mode.
 *
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::setActive(void)
{
    return hscdtd_set_mode(&this->device, HSCDTD_MODE_ACTIVE);
}


/**
 * @brief Set the device state into the force state
 *
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::setStateForce(void)
{
    return hscdtd_set_state(&this->device, HSCDTD_STATE_FORCE);
}


/**
 * @brief Set the device state into the normal state
 *
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::setStateNormal(void)
{
    return hscdtd_set_state(&this->device, HSCDTD_STATE_NORMAL);
}


/**
 * @brief Check if data is ready
 *
 * Check if data is available for reading.
 *
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::isDataReady(void)
{
    return hscdtd_data_ready(&this->device);
}


/**
 * @brief Configure the output data rate.
 *
 * Configure the output date rate of the device in the Normal State.
 *
 * @param odr Valid value for frequency.
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::configureOutputDataRate(hscdtd_odr_t odr)
{
    return hscdtd_set_output_data_rate(&this->device, odr);
}


/**
 * @brief Get the Mag Data and store it in the class object.
 *
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::retrieveMagData(void)
{
    return hscdtd_read_magnetodata(&this->device, &this->mag);
}


/**
 * @brief Apply an offset to the sensor readings
 *
 * @param x_off x Offset in uT
 * @param y_off y Offset in uT
 * @param z_off z Offset in Ut
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::applyOffsetDrift(float x_off, float y_off,
                                             float z_off)
{
    return hscdtd_set_offset(&this->device, x_off, y_off, z_off);
}


/**
 * @brief Set the Data Ready Pin Enabled Status
 *
 * @param den
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::setDataReadyPinEnabledStatus(hscdtd_den_t den)
{
    return hscdtd_set_data_ready_pin_enable(&this->device, den);
}


/**
 * @brief Set the Data Ready Pin Polarity
 *
 * The polarity can be configured as:
 * - Active LOW
 * - Active HIGH (Default).
 * 
 * This option is only available if Data Ready Pin output is enabled.
 *
 * @param drp
 * @return hscdtd_status_t
 */
hscdtd_status_t HSCDTD008A::setDataReadyPinPolarity(hscdtd_drp_t drp)
{
    return hscdtd_set_data_ready_pin_polarity(&this->device, drp);
}


/**
 * @brief Get the temperature value.
 *
 * Get the temperature value after temperature compensation. Only retrieves
 * the value from the register, does not start a temperature measurement.
 *
 * @return int, temperature in degrees (C)
 */
int HSCDTD008A::getTemperature(void)
{
    return hscdtd_read_temp(&this->device);
}
