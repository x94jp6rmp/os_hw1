#include <linux/list.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

#define NUM_OF_PERSON 5

typedef struct _birthday {
   int day;
   int month;
   int year;
   struct list_head list;
}birthday;


static LIST_HEAD(birthday_list);


int birthdayList_init(void)
{
          printk(KERN_INFO “Loading Module\n”);

   birthday *person;
   int i = 0;
   for(i = 0; i < NUM_OF_PERSON; i++)
   {
       person = kmalloc(sizeof(*person), GFP_KERNEL);
       person->day = i+1;
       person->month = i+1;
       person->year = i+1;
       INIT_LIST_HEAD(&person->list);
       list_add_tail(&person->list, &birthday_list);
   }

   printk(KERN_INFO “Display the list:\n”);

   birthday *ptr;
   list_for_each_entry(ptr, &birthday_list, list)
   {
       printk(KERN_INFO “day: %d, month: %d, year: %d\n”,
               ptr->day,
               ptr->month,
               ptr->year);
   }

   printk(KERN_INFO “Display done\n”);

          return 0;
}

void birthdayList_exit(void)
{
   printk(KERN_INFO “Removing Module\n”);

   birthday *ptr, *next;
   list_for_each_entry_safe(ptr, next, &birthday_list, list)
   {
       printk(KERN_INFO “Removing – day: %d, month: %d, year: %d\n”,
               ptr->day,
               ptr->month,
               ptr->year);
       list_del(&ptr->list);
       kfree(ptr);
   }

   printk(KERN_INFO “Memory free done\n”);
}

module_init( birthdayList_init );
module_exit( birthdayList_exit );

MODULE_LICENSE(“GPL”);
MODULE_DESCRIPTION(“BirthdayList Module”);
MODULE_AUTHOR(“daveti”);


