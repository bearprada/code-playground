#include <linux/linkage.h>
#include <linux/kernel.h>
int main()
{
	printk(KERN_EMERG "hello world!!");
	return 1;
}