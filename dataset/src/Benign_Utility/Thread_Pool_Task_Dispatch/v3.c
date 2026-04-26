#include <stdatomic.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void (*work)(void *);
    void *data;
    atomic_bool active;
} slot_c;

void __attribute__((noinline)) __attribute__((used)) dispatch_task_c(slot_c *slots, int n, void (*f)(void *), void *d){
    while (true) {
        for (int i = 0; i < n; i++) {
            bool expected = false;
            if (atomic_compare_exchange_strong(&slots[i].active, &expected, true)) {
                slots[i].work = f;
                slots[i].data = d;
                return;
            }
        }
    }
}

// static void force_use() {
//     slot_c slots[1];
//     dispatch_task_c(slots, 1, NULL, NULL);
// }