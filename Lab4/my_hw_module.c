#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/types.h>
MODULE_AUTHOR("");
MODULE_DESCRIPTION("Lab 1.2, using struct list_head");
MODULE_LICENSE("MIT");
#define LIST_LEN 10
#define MSG_PREF "TEST: "

#define print_msg(msg, ...) printk(KERN_ERR MSG_PREF msg, ##__VA_ARGS__);
typedef struct {
    struct list_head lnode;
    uint32_t val;
} int_node_t;

// Макрос звільнення пам'яті
// do {}while(0)
#define ilfree(list_head) \
    do { \
        int_node_t *__ptr, *__tmp; \
        list_for_each_entry_safe(__ptr, __tmp, (list_head), lnode) { \
        kfree(__ptr); \
} \
} while(0)

// макрос Виводу значень до консолі
#define ilprint(list_head) \
    do { \
        int_node_t *__ptr; \
        print_msg("List: {"); \
        list_for_each_entry(__ptr, (list_head), lnode) { \
            printk(KERN_ERR "\t%i ", __ptr->val); \
        } \
        printk(KERN_ERR "}\n"); \
    } while(0)

// Ініціалізація списку
static struct list_head int_list = LIST_HEAD_INIT(int_list);

// Функція для зсуву списку праворуч
static void task(void) {
    int_node_t *ptr;
    uint32_t result_and = ~0U;
    uint32_t max_value = 0;
    uint32_t min_value = ~0U;
    uint32_t sum = 0;

    list_for_each_entry(ptr, &int_list, lnode) {
        result_and &= ptr->val;

        if (ptr->val > max_value) {
            max_value = ptr->val;
        }

        if (ptr->val < min_value) {
            min_value = ptr->val;
        }

        // Ділити на 25, 9
        ptr->val = ptr->val / 25 / 9;

        // Вліво
        ptr->val <<= 1;

        // Вправо
        ptr->val >>= 1;

        sum += ptr->val;
    }

    print_msg("Побітове AND (&): %u\n", result_and);
    print_msg("Найбільний елемент: %u\n", max_value);
    print_msg("Найменший елемент: %u\n", min_value);
    print_msg("Сума елементів: %u\n", sum);
}

static int __init list_module_init(void) {
    int i;
    int ret = 0;
    print_msg("List allocation start...\n");
    // Виділення памяті під елементи списку
    for (i = 0; i < LIST_LEN; ++i) {
        int_node_t *ptr = (int_node_t *)kmalloc(sizeof(*ptr),
        GFP_KERNEL);
        if (!ptr) {
            print_msg("Can't alloc memory\n");
            ret = -ENOMEM;
            goto alloc_err;
        }
        // Функція для роботи
        get_random_bytes(&ptr->val, sizeof(ptr->val));
        list_add_tail(&ptr->lnode, &int_list);
    }
    print_msg("List allocation finish\n");
    ilprint(&int_list);
    task();
    ilprint(&int_list);
    return 0;
    alloc_err:
    ilfree(&int_list);
    return ret;
}

static void __exit list_module_exit(void) {
    ilfree(&int_list);
    print_msg("Hasta la vista, Kernel!\n");
}

module_init(list_module_init);
module_exit(list_module_exit);
