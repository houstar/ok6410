CC=arm-unknown-linux-uclibceabi
GCC=$(CC)-gcc
LD=$(CC)-ld
OBJCOPY=$(CC)-objcopy
OBJDUMP=$(CC)-objdump

export CC GCC LD OBJCOPY OBJDUMP

led.bin:led.o start.o
	$(LD) -Ttext 0x00000000 start.o led.o -o  led.elf
	$(OBJCOPY) -O  binary -S led.elf led.bin
	$(OBJDUMP) -m arm -D led.elf > led.dis
led.o:led.c
	$(GCC) -c -o led.o led.c
start.o:
	$(GCC) -c start.S
clean:
	rm -f *.o *.elf *.dis *.bin
