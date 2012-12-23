/*Memory map address */
#define GPMCON (*(volatile unsigned long *)(0x7f008820))
#define GPMDAT (*(volatile unsigned long *)(0x7f008824))
#define GPMPUD (*(volatile unsigned long *)(0x7f008828))

void led_init(void)
{
	 GPMPUD &= 0x00;
	 GPMPUD |=(((0x1)<<(2*0)) | ((0x1)<<(2*1)) | ((0x1)<<(2*2)) |
			 ((0x1)<<(2*3));/* pull down enabled*/
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
	GPMDAT |= (((0x1)<<(num-1)));
}
void delay()
{
	volatile int i = 0x10000;
	while(i--);
}
void main()
{
	led_init();
	int i= 0;
	while(1)
	{
		if(i==5)i=0;
		i++;
		led_on(i);
		delay();
		led_off(i-1);
		delay();
	}
}
