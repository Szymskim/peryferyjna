#include "24C16.h"

static void C16_SaveByte(uint8_t adr, uint8_t data)
{
	i2cStart();
	i2cSend(C16_ADDRESS_W);
	i2cSend(adr);
	i2cSend(data);
	i2cStop();
}

static uint8_t C16_LoadByte(uint8_t adr)
{
	uint8_t data;
	i2cStart();
	i2cSend(C16_ADDRESS_W);
	i2cSend(adr);
	i2cSend(C16_ADDRESS_R);
	data = i2cReadAck();
	i2cStop();
	return data;
}