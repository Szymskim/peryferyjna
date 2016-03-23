#include "I2C.h"

#define C16_ADDRESS_W		0b10100000
#define C16_ADDRESS_R		0b10100001

static void C16_SaveByte(uint8_t adr, uint8_t data);

static uint8_t C16_LoadByte(uint8_t adr);

