#include "houstar.h"
void delay()
{
	volatile int i = 0x10000;
	while(i--);
}

void buzzer_init(void)
{
	GPFCON &=(~(0x3)<<(2*15));
	GPFCON |=((0x1)<<(2*15));/*[31:30] PWM_TOUT1 equals 10*/
	GPFPUD &=(~(0x3)<<(2*15));/*pull down/up disabed*/
	GPFDAT &=(~(0x1)<<(15));/*disable pwm*/
}

void buzzer_on(void)
{
	GPFDAT |=((0x1)<<(15));
}

void buzzer_off(void)
{
	GPFDAT &=(~(0x1)<<(15));
}

