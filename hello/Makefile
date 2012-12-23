obj-m :=test.o
KDIR :=/home/houstar/linux-3.0.1/
all:
	make -C $(KDIR) M=$(shell pwd) modules
clean:
	make -C $(KDIR) M=$(shell pwd) clean
