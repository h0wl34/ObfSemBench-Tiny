#include <pthread.h>
#include <stdlib.h>

typedef struct {
    void (*tasks[256])(void *);
    void *args[256];
    int head, tail, count;
    pthread_mutex_t mtx;
    pthread_cond_t not_empty;
} pool_b;

int __attribute__((noinline)) __attribute__((used)) push_task_b(pool_b *p, void (*f)(void *), void *a){
    pthread_mutex_lock(&p->mtx);
    if (p->count == 256) {
        pthread_mutex_unlock(&p->mtx);
        return 0;
    }
    p->tasks[p->tail] = f;
    p->args[p->tail] = a;
    p->tail = (p->tail + 1) % 256;
    p->count++;
    pthread_cond_signal(&p->not_empty);
    pthread_mutex_unlock(&p->mtx);
    return 1;
}

// static void force_use() {
//     pool_b p;
//     push_task_b(&p, NULL, NULL);
// }