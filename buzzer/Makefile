CC=arm-unknown-linux-uclibceabi
GCC=$(CC)-gcc
LD=$(CC)-ld
OBJCOPY=$(CC)-objcopy
OBJDUMP=$(CC)-objdump

export CC GCC LD OBJCOPY OBJDUMP

buzzer.bin:buzzer.o start.o
	$(LD) -Ttext 0x00000000 start.o buzzer.o -o  buzzer.elf
	$(OBJCOPY) -O  binary -S buzzer.elf buzzer.bin
	$(OBJDUMP) -m arm -D buzzer.elf > buzzer.dis
buzzer.o:buzzer.c
	$(GCC) -c -o buzzer.o buzzer.c
start.o:
	$(GCC) -c start.S
clean:
	rm -f *.o *.elf *.dis *.bin
