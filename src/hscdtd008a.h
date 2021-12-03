#ifndef __HSCDTD008A__
#define __HSCDTD008A__

#include <stdint.h>
#include "platform.h"

/**
 * General Constants
 */
#define HSCDTD_NUM_AXIS 				3
#define HSCDTD_MT_PER_LSB_15B			0.00015  // (0.150uT)
#define HSCDTD_UT_PER_LSB_15B			0.150  // (0.150uT)

// I2C address of the device.
#define HSCDTD_ADDR						0x0F

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/* --------------------------------------------------
 * CTRL1 Settings
 */

typedef enum {
	HSCDTD_MODE_STANDBY = 0x00,
	HSCDTD_MODE_ACTIVE = 0x01,
} HSCDTD_CTRL1_PC_t;


typedef enum {
	HSCDTD_ODR_0_5HZ = 0x00,
	HSCDTD_ODR_10HZ = 0x01,
	HSCDTD_ODR_20HZ = 0x10,
	HSCDTD_ODR_100HZ = 0x11,
} HSCDTD_CTRL1_ODR_t;


typedef enum {
	HSCDTD_STATE_NORMAL = 0x00,
	HSCDTD_STATE_FORCE = 0x01,
} HSCDTD_CTRL1_FS_t;


/* --------------------------------------------------
 * CTRL2 Settings
 */


typedef enum {
	HSCDTD_FIFO_DIRECT = 0x00,
	HSCDTD_FIFO_COMP = 0x01,
} HSCDTD_CTRL2_FCO_t;


typedef enum {
	HSCDTD_COMP_OR = 0x00,
	HSCDTD_COMP_AND = 0x01,
} HSCDTD_CTRL2_AOR_t;


typedef enum {
	HSCDTD_FIFO_DISABLE = 0x00,
	HSCDTD_FIFO_ENABLE = 0x01,
} HSCDTD_CTRL2_FF_t;


typedef enum {
	HSCDTD_DRDY_CTRL_DISABLED = 0x00,
	HSCDTD_DRDY_CTRL_ENABLED = 0x01,
} HSCDTD_CTRL2_DEN_t;


typedef enum {
	HSCDTD_DRP_ACTIVE_LOW = 0x00,
	HSCDTD_DRP_ACTIVE_HIGH = 0x01,
} HSCDTD_CTRL2_DRP_t;


/* --------------------------------------------------
 * CTRL4 Settings
 */

typedef enum {
	HSCDTD_RESOLUTION_14_BIT = 0x00,
	HSCDTD_RESOLUTION_15_BIT = 0x01,
} HSCDTD_CTRL4_RS_t;


/* --------------------------------------------------
 * Driver structs
 */

typedef struct {
	float mag_x;
	float mag_y;
	float mag_z;	
} hscdtd_mag_t;


int8_t initialize(void);

int8_t set_mode(HSCDTD_CTRL1_PC_t mode);

int8_t set_output_data_rate(HSCDTD_CTRL1_ODR_t odr);

int8_t set_state(HSCDTD_CTRL1_FS_t state);

int8_t set_fifo_data_storage_method(HSCDTD_CTRL2_FCO_t fco);

int8_t set_fifo_comparision_method(HSCDTD_CTRL2_AOR_t aor);

int8_t set_fifo_enable(HSCDTD_CTRL2_FF_t ff);

int8_t set_data_ready_pin_enable(HSCDTD_CTRL2_DEN_t den);

int8_t set_data_ready_pin_polarity(HSCDTD_CTRL2_DRP_t drp);

int8_t set_resolution(HSCDTD_CTRL4_RS_t resolution);

int8_t who_i_am_check(void);

int8_t offset_calibration(void);

int8_t temperature_compensation(void);

int8_t read_temp(void);

int8_t self_test(void);

int8_t soft_reset(void);

int8_t measure(hscdtd_mag_t *p_mag_data);

int8_t read_magnetodata(hscdtd_mag_t *p_mag_data);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__HSCDTD008A__
