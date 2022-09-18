
/****************************************************************
 * platform_rpi.cpp   
 * HSCDTD008A Library Extention for RPI
 * Tilman Glötzner
 * Original Creation Date: 2022-09-07
 *
 * Distributed as-is; no warranty is given.
 ***************************************************************/

#ifdef RPI
#include "platform.h"
#include "hscdtd008a_driver.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <linux/i2c-dev.h>
#define I2C_ADDR 0x0f
#define device "/dev/i2c-1"
#ifndef I2C_M_RD
#include <linux/i2c.h>
#endif

int fd = -1;

int8_t t_open(void)
{
    fd = open(device, O_RDWR); 
    if (fd >= 0)
    {
       if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
        printf("ioctl error: %s\n", strerror(errno));
        return 1;
       }
    }   
    return (fd < 0);
}

int8_t t_read_register(uint8_t addr,
                       uint8_t reg,
                       uint8_t length,
                       uint8_t *p_buffer)
{
    uint8_t inbuf[32];
    uint8_t outbuf[1];
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset[1];

    // prepare I2C message to select register to be read
    msgs[0].addr = addr;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = outbuf;
 
    outbuf[0] = reg;
   
    // prepare I2C to read selected register  
    msgs[1].addr = addr;
    msgs[1].flags = I2C_M_RD | I2C_M_NOSTART;
    msgs[1].len = length;
    msgs[1].buf = inbuf;

    msgset[0].msgs = msgs;
    msgset[0].nmsgs = 2;

    // i2c message can have up to 32 bytes
    if (length >= 32) 
      return HSCDTD_STAT_ERROR; 
    
    // debug output
    //    printf("t_read_register: reg=0x%x\n", reg);

    // hand over prepared messages to the kernel via ioctl driver for execution
    *p_buffer = 0;
    if (ioctl(fd, I2C_RDWR, &msgset) < 0) {
        printf("ioctl(I2C_RDWR) in i2c_read");
        printf("t_read_register: Error writing to i2c device: %s\n", 
  		strerror(errno));
        printf("t_read_register: addr=0x%x, reg=0x%x, length=%d", addr, reg, length);

        return HSCDTD_STAT_ERROR;
    }

    //copy received bytes into buffer
    strncpy((char*)p_buffer, (char*)inbuf, length); 
    return HSCDTD_STAT_OK;
}

int8_t t_write_register(uint8_t addr,
                        uint8_t reg,
                        uint8_t length,
                        uint8_t *p_buffer)
{
    uint8_t buffer[32];
    struct i2c_msg msgs[1];
    struct i2c_rdwr_ioctl_data msgset[1];

    buffer[0] = reg;
    if (length >= 31) 
      return HSCDTD_STAT_ERROR; 

    strncpy((char*)buffer+1, (char*) p_buffer, length);
   
    // prepare i2c write message 
    msgs[0].addr = addr;
    msgs[0].flags = 0;
    msgs[0].len = length+1;
    msgs[0].buf = buffer;

    msgset[0].msgs = msgs;
    msgset[0].nmsgs = 1;

    // hand over prepared messages to the kernel driver via ioctl for execution
    if (ioctl(fd, I2C_RDWR, &msgset) < 0)
    {
        printf("t_write_register: ioctl(I2C_RDWR) in i2c_write");
	printf("Error writing to i2c device: %s.\n", strerror(errno));
	printf("t_write_register: addr=0x%x, reg=0x%x, length=%d", addr, reg, length);

        return HSCDTD_STAT_ERROR;
    }

    return HSCDTD_STAT_OK;
}

int8_t t_flush(void)
{
    return HSCDTD_STAT_OK;
}


int8_t t_close(void)
{
    close(fd);
    return HSCDTD_STAT_OK;
}


void t_sleep_ms(uint32_t duration_ms)
{
    usleep(duration_ms*1000);
}
#endif
