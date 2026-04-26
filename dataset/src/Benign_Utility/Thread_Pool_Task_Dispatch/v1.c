#include <pthread.h>
#include <stdlib.h>

struct task_a {
    void (*fn)(void *);
    void *arg;
    struct task_a *next;
};

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t cond;
    struct task_a *head;
} pool_a;

void __attribute__((noinline)) __attribute__((used)) push_task_a(pool_a *p, void (*f)(void *), void *a){
    struct task_a *t = (struct task_a *)malloc(sizeof(struct task_a));
    t->fn = f; t->arg = a; t->next = NULL;
    pthread_mutex_lock(&p->lock);
    t->next = p->head;
    p->head = t;
    pthread_cond_signal(&p->cond);
    pthread_mutex_unlock(&p->lock);
}