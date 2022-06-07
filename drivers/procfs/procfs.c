#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#define MAX_USER_SIZE 1024
static struct proc_dir_entry *bart_proc = NULL;
static char data_buffer[MAX_USER_SIZE];

ssize_t bart_proc_read(struct file *file, char __user *user, size_t size, loff_t *off){
	return copy_to_user(user, "hello\n", 7) ? 0 : 7;
}

ssize_t bart_proc_write(struct file *file, const char __user *user, size_t size, loff_t *off){
	memset(data_buffer, 0x0, sizeof(data_buffer));
	if (size > MAX_USER_SIZE)
	{
		size = MAX_USER_SIZE;
	}
	copy_from_user(data_buffer, user, size);
	printk("info ontvangen: '%s'\n", data_buffer);
	return size;
}
static const struct proc_ops bart_proc_fops = {
	.proc_read = bart_proc_read,
	.proc_write = bart_proc_write,
};
static int __init gpio_driver_init(void)
{
	bart_proc = proc_create("bart-gpio", 0666, NULL, &bart_proc_fops);
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
MODULE_DESCRIPTION("POC ProcFS");
MODULE_VERSION("1.0");
