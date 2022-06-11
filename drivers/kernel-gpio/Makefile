file := kernel-gpio
obj-m += $(file).o

KDIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(shell pwd) modules 

clean:
	make -C $(KDIR) M=$(shell pwd) clean

install: all
	-sudo rmmod $(file) 
	sudo insmod $(file).ko