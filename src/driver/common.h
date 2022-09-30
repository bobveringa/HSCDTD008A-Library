/*
 * common.h
 *
 *  Created on: Sep 25, 2022
 *      Author: tilman
 */

#ifndef SRC_DRIVER_COMMON_H_
#define SRC_DRIVER_COMMON_H_

typedef enum {
    HSCDTD_STATE_NORMAL = 0b00,
    HSCDTD_STATE_FORCE = 0b01,
} hscdtd_state_t;

typedef enum {
    HSCDTD_MODE_STANDBY = 0b00,
    HSCDTD_MODE_ACTIVE = 0b01,
} hscdtd_mode_t;

typedef struct {
    uint8_t addr;
    char* device;
    int8_t fd;
    hscdtd_state_t state;
    hscdtd_mode_t mode;
} hscdtd_device_t;


#endif /* SRC_DRIVER_COMMON_H_ */
