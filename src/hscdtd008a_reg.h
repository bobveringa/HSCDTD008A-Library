#ifndef __HSCDTD008A_REGS__
#define __HSCDTD008A_REGS__

#include <stdint.h>
#include "platform.h"


/**
 * Registers
 */
#define HSCDTD_REG_SELFTEST_RESP		0x0C
#define HSCDTD_REG_MORE_INFO			0x0D
#define HSCDTD_REG_MORE_INFO_ALPS		0x0E
#define HSCDTD_REG_WIA					0x0F
#define HSCDTD_REG_XOUT_L				0x10
#define HSCDTD_REG_XOUT_H				0x11
#define HSCDTD_REG_YOUT_L				0x12
#define HSCDTD_REG_YOUT_H				0x13
#define HSCDTD_REG_ZOUT_L				0x14
#define HSCDTD_REG_ZOUT_H				0x15

#define HSCDTD_REG_STATUS				0x18
#define HSCDTD_REG_FIFO_P_STATUS		0x19
#define HSCDTD_REG_CTRL1				0x1B
#define HSCDTD_REG_CTRL2				0x1C
#define HSCDTD_REG_CTRL3				0x1D
#define HSCDTD_REG_CTRL4				0x1E

#define HSCDTD_REG_OFFSET_X_L			0x20
#define HSCDTD_REG_OFFSET_X_H			0x21
#define HSCDTD_REG_OFFSET_Y_L			0x22
#define HSCDTD_REG_OFFSET_Y_H			0x23
#define HSCDTD_REG_OFFSET_Z_L			0x24
#define HSCDTD_REG_OFFSET_Z_H			0x25
#define HSCDTD_REG_INTR_THR_L			0x26
#define HSCDTD_REG_INTR_THR_H			0x27

#define HSCDTD_REG_TEMP					0x31


#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef struct {
	uint8_t ORDY : 1;
	uint8_t TRDY : 1;
	uint8_t FFU : 1;
	uint8_t reserved_0 : 2;
	uint8_t DOR : 1;
	uint8_t DRDY : 1;
	uint8_t reserved_1 : 1;
} HSCDTD_STAT_t;


typedef struct {
	uint8_t FP : 4;
	uint8_t reserved_0 : 4;
} HSCDTD_FFPT_t;


typedef struct {
	uint8_t reserved_0 : 1;
	uint8_t FS : 1;
	uint8_t reserved_1 : 1;
	uint8_t ODR : 2;
	uint8_t reserved_2 : 2;
	uint8_t PC : 1;

} HSCDTD_CTRL1_t;


typedef struct {
	uint8_t DOS : 1;
	uint8_t DTS : 1;
	uint8_t DRP : 1;
	uint8_t DEN : 1;
	uint8_t FF : 1;
	uint8_t AOR : 1;
	uint8_t FCO : 1;
	uint8_t AVG : 1;
} HSCDTD_CTRL2_t;

typedef struct {
	uint8_t OCL : 1;
	uint8_t TCS : 1;
	uint8_t reserved_0 : 2;
	uint8_t STC : 1;
	uint8_t reserved_1 : 1;
	uint8_t FRC : 1;
	uint8_t SRST : 1;
} HSCDTD_CTRL3_t;


typedef struct {
	uint8_t reserved_0 : 3;
	uint8_t AS : 1;
	uint8_t RS : 1;
	uint8_t reserved_1 : 1;
	uint8_t MMD : 2;
} HSCDTD_CTRL4_t;


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__HSCDTD008A_REGS__
