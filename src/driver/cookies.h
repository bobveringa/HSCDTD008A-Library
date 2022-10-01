#ifndef __PLATFORM_COOKIES__
#define __PLATFORM_COOKIES__

#include <stdint.h>


typedef struct platform_cookie platform_cookie_t;

typedef struct {
    uint8_t addr;
    platform_cookie_t platform_cookie;

} hscdtd_transport_cookie_t;


#ifdef ARDUINO
struct platform_cookie {

};
#endif //ARDUINO

#ifdef RPI
struct platform_cookie {
    char* device;
    int8_t fd;
};
#endif //RPI

#endif //__PLATFORM_COOKIES__
