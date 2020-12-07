#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>

#include <hello1.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("AK-2 Lab5 hello1\n");
MODULE_AUTHOR("Holovash Anastasia IV-82\n");
EXPORT_SYMBOL(hello);

static int __init hello1_init(void)
{
        pr_info("hello1 inited\n");
        return 0;
}

static void __exit hello1_exit(void)
{
        pr_info("hello1 exited\n");
}

module_init(hello1_init);

module_exit(hello1_exit);

static int hello(uint n)
{
        int i;
        if (n < 0) {
                pr_err("ERROR! n < 0\n");
        }
        else if (n == 0) {
                pr_warn("WARNING! n = 0\n");
        }
        else if (n >= 5 && n <= 10) {
                pr_warn("WARNING! 5 <= n <= 10\n");
        }
        else if (n > 10) {
                pr_err("ERROR! n > 10\n");
                return -EINVAL;
        }
        for (i = 0; i < n; i++) {
                pr_info("Hello, world!\n");
        }
        return 0;
}
