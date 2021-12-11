#include "platform.h"

#include <Arduino.h>
#include <Wire.h>


int8_t t_open(void)
{
    Wire.begin();
    Wire.setClock(I2C_MODE_STD);
    return 0;
}

int8_t t_read_register(uint8_t addr,
                       uint8_t reg,
                       uint8_t length,
                       uint8_t *p_buffer)
{
    uint8_t status;
    int8_t i = 0;

    Wire.beginTransmission(addr);
    Wire.write(reg);
    status = Wire.endTransmission();
    if (status != 0)
        return -status;

    Wire.requestFrom(addr, length);

    for (i = 0; i < length; i++) {
        p_buffer[i] = Wire.read();
    }
    return 0;
}

int8_t t_write_register(uint8_t addr,
                        uint8_t reg,
                        uint8_t length,
                        uint8_t *p_buffer)
{
    uint8_t status;

    Wire.beginTransmission(addr);
    Wire.write(reg);

    for (int8_t i = 0; i < length; i++)
    {
        Wire.write(p_buffer[i]);
    }

    status = Wire.endTransmission();
    if (status != 0)
        return -status;
    return 0;
}

int8_t t_flush(void)
{
    while (Wire.available() > 0) {
        Wire.read();  // just flush the data.
    }
    return 0;
}


int8_t t_close(void)
{
    uint8_t status;

    status = Wire.endTransmission(true);
    if (status != 0)
        return -1;
    return 0;
}


void t_sleep_ms(uint32_t duration_ms)
{
    delay(duration_ms);
}
