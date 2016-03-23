#include "I2C.h"

#define DS1307_ADDRESS_W 	0b11010000
#define DS1307_ADDRESS_R 	0b11010001

static uint16_t ds1307_date2days(uint8_t y, uint8_t m, uint8_t d);

uint8_t ds1307_getdayofweek(uint8_t y, uint8_t m, uint8_t d);

uint8_t ds1307_setdate(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);

void ds1307_getdate(uint8_t *year, uint8_t *month, uint8_t *day, uint8_t *hour, uint8_t *minute, uint8_t *second);
