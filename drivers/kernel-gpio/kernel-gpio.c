#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#define MAX_USER_SIZE 1024
#include <linux/gpio.h>
static struct proc_dir_entry *bart_proc = NULL;
static char data_buffer[MAX_USER_SIZE];

static void gpio_pin_on(unsigned int pin){
	gpio_set_value(pin, 1);
}
static void gpio_pin_off(unsigned int pin){
	gpio_set_value(pin, 0);
}

ssize_t bart_proc_read(struct file *file, char __user *user, size_t size, loff_t *off){
	return copy_to_user(user, "hello\n", 7) ? 0 : 7;
}

ssize_t bart_proc_write(struct file *file, const char __user *user, size_t size, loff_t *off){
	memset(data_buffer, 0x0, sizeof(data_buffer));
unsigned int pin = UINT_MAX;
	unsigned int value = UINT_MAX;

	memset(data_buffer, 0x0, sizeof(data_buffer));

	if (size > MAX_USER_SIZE)
	{
		size = MAX_USER_SIZE;
	}

	if (copy_from_user(data_buffer, user, size))
		return 0;

	printk("Data buffer: %s\n", data_buffer);

	if (sscanf(data_buffer, "%d,%d", &pin, &value) != 2)
	{
		printk("Inproper data format submitted\n");
		return size;
	}

	if (gpio_is_valid(pin) == 0)
	{
		printk("Invalid pin number submitted\n");
		return size;
	}
	if (value != 0 && value != 1)
	{
		printk("Invalid on/off value\n");
		return size;
	}

	printk("You said pin %d, value %d\n", pin, value);
	gpio_direction_output(pin, 0);
	if (value == 1)
	{
		gpio_pin_on(pin);
	} else if (value == 0)
	{
		gpio_pin_off(pin);
	}

	return size;	
}
static const struct proc_ops bart_proc_fops = {
	.proc_read = bart_proc_read,
	.proc_write = bart_proc_write,
};
static int __init gpio_driver_init(void)
{
	bart_proc = proc_create("bart-gpio", 0666, NULL, &bart_proc_fops);
	//int i;
	//for(i = 1; i <= 40; i++){
	//	gpio_request(i, NULL);
	//	gpio_direction_output(i, 0);
//}
	printk("Welcome to my driver!\n");
	return 0;
}

static void __exit gpio_driver_exit(void)
{
	printk("Leaving my driver!\n");
	proc_remove(bart_proc);
	return;
}

module_init(gpio_driver_init);
module_exit(gpio_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bart");
MODULE_DESCRIPTION("POC Linux kernel GPIO library");
MODULE_VERSION("1.0");
