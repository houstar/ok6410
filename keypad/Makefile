CC=arm-unknown-linux-uclibceabi
GCC=$(CC)-gcc
LD=$(CC)-ld
OBJCOPY=$(CC)-objcopy
OBJDUMP=$(CC)-objdump

export CC GCC LD OBJCOPY OBJDUMP

key.bin:led.o buzzer.o keypad.o start.o
	$(LD) -Ttext 0x00000000 start.o led.o buzzer.o keypad.o  -o  keypad.elf
	$(OBJCOPY) -O  binary -S keypad.elf keypad.bin
	$(OBJDUMP) -m arm -D keypad.elf > keypad.dis
led.o:led.c led.h
	$(GCC) -c -o led.o led.c
buzzer.o:buzzer.c buzzer.h
	$(GCC) -c -o buzzer.o buzzer.c 
keypad.o:keypad.c
	$(GCC) -c keypad.c
start.o:
	$(GCC) -c start.S
clean:
	rm -f *.o *.elf *.dis *.bin
