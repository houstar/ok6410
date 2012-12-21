#include "led.h"
void led_init(void)
{
	 GPMPUD &= 0x00;
	 GPMPUD |=(((0x2)<<0) | ((0x2)<<1) | ((0x2)<<2) |
			 ((0x2)<<3));/* pull up enabled*/
	 GPMCON &=0x0000;
	 GPMCON |= 0x1111;
	 GPMDAT = 0xf;
}
void led_on(int num)
{
	GPMDAT &= (~((0x1)<<(num-1)));
}

void led_off(int num)
{
	GPMDAT |= (~((0x1)<<(num-1)));
}
