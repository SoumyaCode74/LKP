/* Step 1: Include the following header files */

#include <linux/module.h>
#include <linux/kernel.h>

/* Step 2: Declare the License and Author information */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chin Tapak Tum Tum");

/* Step 3: Define the functions for module init and module exit */

static int test_hello_init(void){
	printk(KERN_INFO "%s: In init\n", __func__);
	return 0;
}

static void test_hello_exit(void){
	printk(KERN_INFO "%s: In exit\n", __func__);
}

/* Step 4: Assign the function names to the corresponding macros: module_init and module_exit */
module_init(test_hello_init);
module_exit(test_hello_exit);
