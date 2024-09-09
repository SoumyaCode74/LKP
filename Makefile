obj-m := hello.o
obj-m += pcd.o
#ARCH=arm
#CC=arm-linux-gnueabihf-
KERN_DIR=/lib/modules/$(shell uname -r)/build/

#target:
#	make ARCH=${ARCH} CROSS_COMPILE=${CC} -C ${KERN_DIR} M=${PWD} modules

#target-clean:
#	make ARCH=${ARCH} CROSS_COMPILE=${CC} -C ${KERN_DIR} M=${PWD} clean

host:
	make -C ${KERN_DIR} M=${PWD} modules

host-clean:
	make -C ${KERN_DIR} M=${PWD} clean
	
#target-help:
#	make ARCH=${ARCH} CROSS_COMPILE=${CC} -C ${KERN_DIR} M=${PWD} help
	
host-help:
	make -C ${KERN_DIR} M=${PWD} help
