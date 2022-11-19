#ifndef __PLATFORM_COOKIES__
#define __PLATFORM_COOKIES__

#include <stdint.h>


#ifdef ARDUINO
typedef struct {

} platform_cookie_t;
#endif //ARDUINO

#ifdef RPI
typedef struct {
    const char* device;
    int8_t fd;
} platform_cookie_t;
#endif //RPI

typedef struct {
    uint8_t addr;
    platform_cookie_t platform_cookie;

} hscdtd_transport_cookie_t;

#endif //__PLATFORM_COOKIES__
