#ifndef __TRANSPORT__
#define __TRANSPORT__

#include <stdint.h>
#include "hscdtd008a_driver.h"


hscdtd_status_t read_register(hscdtd_device_t *p_dev,
                              uint8_t reg,
                              void *p_buffer);


hscdtd_status_t read_register_multi(hscdtd_device_t *p_dev,
                                    uint8_t reg,
                                    uint8_t length,
                                    void *p_buffer);

hscdtd_status_t write_register(hscdtd_device_t *p_dev,
                               uint8_t reg,
                               void *p_buffer);

#endif  //__TRANSPORT__