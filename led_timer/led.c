/*Memory map address */
#define GPMCON (*(volatile unsigned long *)(0x7f008820))
#define GPMDAT (*(volatile unsigned long *)(0x7f008824))
#define GPMPUD (*(volatile unsigned long *)(0x7f008828))

#define TCFG0	(*(volatile unsigned long *)(0x7f006000))
#define TCFG1	(*(volatile unsigned long *)(0x7f006004))
#define TCON	(*(volatile unsigned long *)(0x7f006008))
#define TCNTB0	(*(volatile unsigned long *)(0x7f00600c))
#define TCMPB0	(*(volatile unsigned long *)(0x7f006010))
#define TCNTO0	(*(volatile unsigned long *)(0x7f006014))
#define TCNTB1	(*(volatile unsigned long *)(0x7f006018))
#define TCMPB1	(*(volatile unsigned long *)(0x7f00601c))
#define TCNTO1	(*(volatile unsigned long *)(0x7f006020))
#define TCNTB2	(*(volatile unsigned long *)(0x7f006024))
#define TCNTO2	(*(volatile unsigned long *)(0x7f00602c))
#define TCNTB3	(*(volatile unsigned long *)(0x7f006030))
#define TCNTO3	(*(volatile unsigned long *)(0x7f006038))
#define TCNTB4	(*(volatile unsigned long *)(0x7f00603c))
#define TCNTO4	(*(volatile unsigned long *)(0x7f006040))
#define TINT_CSTAT (*(volatile unsigned long *)(0x7f006044))

#define PCLK (66000000)
#define HCLK (133000000)



void led_init(void)
{
	 GPMPUD &= 0x00;
	 GPMPUD |=(((0x1)<<(2*0)) | ((0x1)<<(2*1)) | ((0x1)<<(2*2)) |
			 ((0x1)<<(2*3)));/* pull down enabled*/
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
void udelay(int usec)
{
	unsigned int val = PCLK/1000000-1;
	TCFG0 &= ~(0xff<<8);
	TCFG0 |= 0<<8;
	TCFG1 &- ~(0xff<<8);
	TCFG1 |= 0<<8;
	TCNTB2 = val;
	TCON &= ~(0xf<<12);
	TCON |= 0xb<<12;
	TCON &= ~(2<<12);
	while(usec--)
	{
		while(TCNTO2>=val>>1);
		while(TCNTO2<val>>1);
	};
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
		udelay(1000);
		led_off(i-1);
		udelay(1000);
	}
}
