#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kdev_t.h>

#define DEV_MEM_SIZE						(512)

char device_buffer[DEV_MEM_SIZE];

/* Create device number for our device */
dev_t device_number;

/* Create cdev struct for character device */
struct cdev pcd_cdev;

/* Create file operations struct for character device driver */
struct file_operations pcd_fops;
 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chin Tapak Tum Tum");
MODULE_DESCRIPTION("A pseudo character device's driver for tutorial");

static int __init __init_pcd_driver_module(void){
	/* 1. Allocate space in VFS for our eeprom devices */
	alloc_chrdev_region(&device_number, 0, 1, "eeprom");
	
	/* 1.1 Print the major and minor numbers of our devices */
	printk("Major number: %d, %d\n", MAJOR(device_number), ( (device_number >> 20) & 0xFFF ) );
	printk("Minor number: %d, %d\n", MINOR(device_number), ( device_number & ( 0xFFFFF ) ) );
	
	/* 2. Initialize the cdev structure with fops */
	cdev_init(&pcd_cdev, &pcd_fops);
	pcd_cdev.owner = THIS_MODULE;
	pcd_fops.read = pcd_read;
	pcd_fops.write = pcd_write;
	pcd_fops.open = pcd_open;
	pcd_fops.release = 
	pcd_fops.llseek = pcd_lseek;
	
	/* 3. Register device to VFS */
	cdev_add(&pcd_cdev, device_number, 1);
	
	return 0;	
}

static ssize_t pcd_read (struct file *, char __user *, size_t, loff_t *){
	return 0;
}

static ssize_t pcd_write (struct file *, const char __user *, size_t, loff_t *){
	return 0;
}

static loff_t pcd_lseek (struct file *, loff_t, int){
	return 0;
}


static void __exit __deinit_pcd_driver_module(void){
	printk("Driver unloaded\n");
}

module_init(__init_pcd_driver_module);
module_exit(__deinit_pcd_driver_module);
