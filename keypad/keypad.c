#include "houstar.h"
#include "led.h"
#include "buzzer.h"

#define KEY1 (0x3e)
#define KEY2 (0x3d)
#define KEY3 (0x3b)
#define KEY4 (0x37)
#define KEY5 (0x2f)
#define KEY6 (0x1f)

#define PRESS_KEY1 ((GPNDAT & KEY1) != KEY1)
#define PRESS_KEY2 ((GPNDAT & KEY2) != KEY2)
#define PRESS_KEY3 ((GPNDAT & KEY3) != KEY3)
#define PRESS_KEY4 ((GPNDAT & KEY4) != KEY4)
#define PRESS_KEY5 ((GPNDAT & KEY5) != KEY5)
#define PRESS_KEY6 ((GPNDAT & KEY6) != KEY6)

void keypad_init(void)
{
	led_init();
	buzzer_init();
	GPNCON &=((0xffffffff)<<(2*6));
	GPNPUD = 0x00000555;
}

void  keypress()
{
	while(1)
	{
		if(PRESS_KEY1)
		{
			led_on(1);
			delay();
			led_off(1);
		}
		else if(PRESS_KEY2)
		{
			led_on(2);
			delay();
			led_off(2);
		}
		else if(PRESS_KEY3)
		{
			led_on(3);
			delay();
			led_off(3);
		}
		else if(PRESS_KEY4)
		{
			led_on(4);
			delay();
			led_off(4);
		}
		else if(PRESS_KEY5)
		{
			buzzer_on();
			delay();
			buzzer_off();
		}
		else 
		{
			led_off(1);led_off(2);
			led_off(3);led_off(4);
			buzzer_off();
		}
	}
}
void main()
{
	keypad_init();
	keypress();
}
