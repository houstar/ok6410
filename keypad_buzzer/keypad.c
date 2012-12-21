#include "houstar.h"
#include "buzzer.h"
void keypad_init(void)
{
	buzzer_init();
	GPNCON &=((0xffffffff)<<(2*6));
	GPNPUD = 0x00000555;
}
unsigned int keyScan(void)
{
	if((GPNDAT & 0x3f) != 0x3f )
		return 1;
	else
		return 0;
}

void keypad_buzzer(void)
{
	unsigned int keyStatus;
	while(1)
	{
		keyStatus = keyScan();
		if(keyStatus)
		{
			buzzer_on();
			delay();
			buzzer_off();
		}
		else
			buzzer_off();
	}
}

void main()
{
	keypad_init();
	buzzer_off();
	keypad_buzzer();
}
