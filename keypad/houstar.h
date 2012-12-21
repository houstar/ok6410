#ifndef HOUSTAR_H
#define HOUSTAR_H
/*
 * GPIO
 */
#define GPFCON (*(volatile unsigned long *)(0x7f0080a0))
#define GPFDAT (*(volatile unsigned long *)(0x7f0080a4))
#define GPFPUD (*(volatile unsigned long *)(0x7f0080a8))

#define GPMCON (*(volatile unsigned long *)(0x7f008820))
#define GPMDAT (*(volatile unsigned long *)(0x7f008824))
#define GPMPUD (*(volatile unsigned long *)(0x7f008828))

#define GPNCON (*(volatile unsigned long *)(0x7f008830))
#define GPNDAT (*(volatile unsigned long *)(0x7f008834))
#define GPNPUD (*(volatile unsigned long *)(0x7f008838))

#endif //HOUSTAR_H
