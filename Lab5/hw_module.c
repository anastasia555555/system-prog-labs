#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/random.h>

#define DEVICE_NAME "random_bits_device"
#define BUF_SIZE 1024

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nastya");
MODULE_DESCRIPTION("A kernel module to generate and read random bits");

static int major_number;
static char buffer[BUF_SIZE];

static int device_open(struct inode *inode, struct file *file)
{
    try_module_get(THIS_MODULE);
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    module_put(THIS_MODULE);
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    unsigned int rand_bit;

    get_random_bytes(&rand_bit, sizeof(rand_bit));

    if (copy_to_user(buffer, &rand_bit, sizeof(rand_bit)) != 0) {
        return -EFAULT;
    }

    return sizeof(rand_bit);
}

static struct file_operations fops = {
    .read = device_read,
    .open = device_open,
    .release = device_release,
};

static int __init random_bits_init(void)
{
    major_number = register_chrdev(0, DEVICE_NAME, &fops);

    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }

    printk(KERN_INFO "Random Bits Device: registered correctly with major number %d\n", major_number);

    return 0;
}

static void __exit random_bits_exit(void)
{
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Random Bits Device: unregistered\n");
}

module_init(random_bits_init);
module_exit(random_bits_exit);

// Використовуємо команду cat 
// для читання з /dev/random_bits_device 
// і отримання випадкових бітів.