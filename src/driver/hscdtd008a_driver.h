#ifndef __HSCDTD008A_DRIVER__
#define __HSCDTD008A_DRIVER__

#include <stdint.h>
#include "platform.h"

/**
 * General Constants
 */
#define HSCDTD_NUM_AXIS                 3
#define HSCDTD_UT_PER_LSB_15B           0.150  // (0.150uT)

// I2C address of the device.
#define HSCDTD_DEFAULT_ADDR             0x0C
#define HSCDTD_ALT_ADDR                 0x0F

// Some useful numbers for general operations
#define HSCDTD_15BIT_MAX_VALUE          2457.6

// If we are compiling for
#ifdef __cplusplus
extern "C"
{
#endif  // __cplusplus

/* --------------------------------------------------
 * CTRL1 Settings
 */

typedef enum {
    HSCDTD_MODE_STANDBY = 0b00,
    HSCDTD_MODE_ACTIVE = 0b01,
} hscdtd_mode_t;

typedef enum {
    HSCDTD_ODR_0_5HZ = 0b00,
    HSCDTD_ODR_10HZ = 0b01,
    HSCDTD_ODR_20HZ = 0b10,
    HSCDTD_ODR_100HZ = 0b11,
} hscdtd_odr_t;


typedef enum {
    HSCDTD_STATE_NORMAL = 0b00,
    HSCDTD_STATE_FORCE = 0b01,
} hscdtd_state_t;


/* --------------------------------------------------
 * CTRL2 Settings
 */


typedef enum {
    HSCDTD_FCO_DIRECT = 0b00,
    HSCDTD_FCO_COMP = 0b01,
} hscdtd_fco_t;


typedef enum {
    HSCDTD_AOR_OR = 0b00,
    HSCDTD_AOR_AND = 0b01,
} hscdtd_aor_t;


typedef enum {
    HSCDTD_FF_DISABLE = 0b00,
    HSCDTD_FF_ENABLE = 0b01,
} hscdtd_ff_t;


typedef enum {
    HSCDTD_DEN_DISABLED = 0b00,
    HSCDTD_DEN_ENABLED = 0b1,
} hscdtd_den_t;


typedef enum {
    HSCDTD_DRP_ACTIVE_LOW = 0b00,
    HSCDTD_DRP_ACTIVE_HIGH = 0b01,
} hscdtd_drp_t;


/* --------------------------------------------------
 * CTRL4 Settings
 */

typedef enum {
    HSCDTD_RESOLUTION_14_BIT = 0b00,
    HSCDTD_RESOLUTION_15_BIT = 0b01,
} hscdtd_res_t;


/* --------------------------------------------------
 * Driver types
 */

typedef struct {
    float mag_x;
    float mag_y;
    float mag_z;
} hscdtd_mag_t;


typedef struct {
    uint8_t addr;
    hscdtd_state_t state;
    hscdtd_mode_t mode;
} hscdtd_device_t;


typedef enum {
    HSCDTD_STAT_OK = 0x00,
    HSCDTD_STAT_ERROR,
    HSCDTD_STAT_TRANSPORT_ERROR,
    HSCDTD_STAT_NO_DATA,
    HSCDTD_STAT_CHECK_FAILED,
    HSCDTD_STAT_UNKNOWN,
    HSCDTD_STAT_USER_ERROR,
} hscdtd_status_t;


hscdtd_status_t hscdtd_configure_virtual_device(hscdtd_device_t *p_dev,
                                                uint8_t addr);

hscdtd_status_t hscdtd_initialize(hscdtd_device_t *p_dev);

hscdtd_status_t hscdtd_set_mode(hscdtd_device_t *p_dev, hscdtd_mode_t mode);

hscdtd_status_t hscdtd_set_output_data_rate(hscdtd_device_t *p_dev,
                                            hscdtd_odr_t odr);

hscdtd_status_t hscdtd_set_state(hscdtd_device_t *p_dev,
                                 hscdtd_state_t state);

hscdtd_status_t hscdtd_set_fifo_data_storage_method(hscdtd_device_t *p_dev,
                                                    hscdtd_fco_t fco);

hscdtd_status_t hscdtd_set_fifo_comparision_method(hscdtd_device_t *p_dev,
                                                   hscdtd_aor_t aor);

hscdtd_status_t hscdtd_set_fifo_enable(hscdtd_device_t *p_dev,
                                       hscdtd_ff_t ff);

hscdtd_status_t hscdtd_set_data_ready_pin_enable(hscdtd_device_t *p_dev,
                                                 hscdtd_den_t den);

hscdtd_status_t hscdtd_set_data_ready_pin_polarity(hscdtd_device_t *p_dev,
                                                   hscdtd_drp_t drp);

hscdtd_status_t hscdtd_set_resolution(hscdtd_device_t *p_dev,
                                      hscdtd_res_t resolution);

hscdtd_status_t hscdtd_who_i_am_check(hscdtd_device_t *p_dev);

hscdtd_status_t hscdtd_offset_calibration(hscdtd_device_t *p_dev);

hscdtd_status_t hscdtd_temperature_compensation(hscdtd_device_t *p_dev);

int8_t hscdtd_read_temp(hscdtd_device_t *p_dev);

hscdtd_status_t hscdtd_self_test(hscdtd_device_t *p_dev);

hscdtd_status_t hscdtd_soft_reset(hscdtd_device_t *p_dev);

hscdtd_status_t hscdtd_measure(hscdtd_device_t *p_dev,
                               hscdtd_mag_t *p_mag_data);

hscdtd_status_t hscdtd_read_magnetodata(hscdtd_device_t *p_dev,
                                        hscdtd_mag_t *p_mag_data);

hscdtd_status_t hscdtd_data_ready(hscdtd_device_t *p_dev);

hscdtd_status_t hscdtd_set_offset(hscdtd_device_t *p_dev,
                                  float x_off, float y_off, float z_off);


#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  //__HSCDTD008A_DRIVER__
