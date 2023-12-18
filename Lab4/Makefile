ifneq ($(KERNELRELEASE),)
obj-m := hw_module.o
else
KDIR ?= /lib/modules/`uname -r`/build
default:
$(MAKE) -C $(KDIR) M=$$PWD
clean:
$(MAKE) -C $(KDIR) M=$$PWD clean
endif