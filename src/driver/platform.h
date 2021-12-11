#ifndef __PLATFORM__
#define __PLATFORM__

#include <stdint.h>

#define I2C_MODE_STD            100000
#define I2C_MODE_FAST           400000
#define I2C_MODE_FAST_PLUS      1000000
#define I2C_MODE_HIGH_SPEED     3400000

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/**
 * @brief Open a connection with the device.
 *
 * @return 0 on success.
 */
int8_t t_open(void);

/**
 * @brief Read registers from the device.
 *
 *
 * @param addr Device address.
 * @param reg Register start reading.
 * @param length Number of register to read.
 * @param p_buffer Pointer to buffer for the result.
 *
 * @return 0 on success.
 */
int8_t t_read_register(uint8_t addr,
                       uint8_t reg,
                       uint8_t length,
                       uint8_t *p_buffer);


/**
 * @brief Write registers to the device.
 *
 * @param addr Device address.
 * @param reg Register to start writing.
 * @param length  Number of registers to write.
 * @param p_buffer Pointer of buffer with data.
 *
 * @return 0 on success.
 */
int8_t t_write_register(uint8_t addr,
                        uint8_t reg,
                        uint8_t length,
                        uint8_t *p_buffer);

/**
 * @brief Flush the connection.
 *
 * @return 0 on success.
 */
int8_t t_flush(void);


/**
 * @brief Close the connection.
 *
 * @return 0 on success.
 */
int8_t t_close(void);


/**
 * @brief Sleep for the provided duration.
 *
 * @param duration_ms Duration to sleep in milliseconds.
 */
void t_sleep_ms(uint32_t duration_ms);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__PLATFORM__
