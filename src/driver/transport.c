#include "transport.h"
#include "common.h"

// Read limit is equal to the number of available registers.
#define HSCDTD_TRANSPORT_READ_LIMIT 0x32

/**
 * @brief Read a single register from the sensor.
 *
 * @param p_dev Pointer to device struct.
 * @param reg Register to read.
 * @param p_buffer Pointer to buffer to store result.
 * @return hscdtd_status.
 */
hscdtd_status_t read_register(hscdtd_device_t *p_dev,
                              uint8_t reg,
                              void *p_buffer)
{
    // No need to do any checks here.
    // This function serves as a way to easily read single registers.
    // Just reuses all the checks for the multi read.
    return read_register_multi(p_dev, reg, 1, p_buffer);
}

/**
 * @brief Read multiple registers from the sensor.
 *
 * @param p_dev Pointer to device struct.
 * @param reg Register to start reading.
 * @param length Number of registers to read.
 * @param p_buffer Pointer to buffer to store result.
 * @return hscdtd_status.
 */
hscdtd_status_t read_register_multi(hscdtd_device_t *p_dev,
                                    uint8_t reg,
                                    uint8_t length,
                                    void *p_buffer)
{
    int8_t status;

    // Check if result buffer is ok.
    if (!p_buffer) {
        return HSCDTD_STAT_TRANSPORT_ERROR;
    }

    status = t_read_register( reg, length, (uint8_t* ) p_buffer, p_dev);
    // Check if the read request does not exceed the chip's limits.
    if (length > HSCDTD_TRANSPORT_READ_LIMIT) {
        return HSCDTD_STAT_USER_ERROR;
    }

    if (status != 0) {
        return HSCDTD_STAT_TRANSPORT_ERROR;
    }
    return HSCDTD_STAT_OK;
}


/**
 * @brief Write register to the sensor.
 *
 * @param p_dev Pointer to device struct.
 * @param reg Register to write.
 * @param p_buffer Pointer to buffer to get value from.
 * @return hscdtd_status.
 */
hscdtd_status_t write_register(hscdtd_device_t *p_dev,
                               uint8_t reg,
                               void *p_buffer)
{
    return write_register_multi(p_dev, reg, 1, p_buffer);
}


/**
 * @brief Write multiple registers to the sensor.
 *
 * @param p_dev Pointer to device struct.
 * @param reg Register to write.
 * @param length Number of registers to write.
 * @param p_buffer Pointer to start of buffer.
 * @return hscdtd_status.
 */
hscdtd_status_t write_register_multi(hscdtd_device_t *p_dev,
                                     uint8_t reg,
                                     uint8_t length,
                                     void *p_buffer)
{
    int8_t status;

    // Check if data buffer pointer is ok.
    if (!p_buffer) {
        return HSCDTD_STAT_TRANSPORT_ERROR;
    }

    status = t_write_register( reg, length, (uint8_t* ) p_buffer, p_dev);
    if (status != 0) {
        return HSCDTD_STAT_TRANSPORT_ERROR;
    }
    return HSCDTD_STAT_OK;
}
