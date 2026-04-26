#include <stdlib.h>

struct node { int k, v; struct node *p, *n; };

int __attribute__((noinline)) __attribute__((used)) manage_cache_b(struct node **head, struct node **tail, int *sz, int cap, int k, int v) {
    struct node *c = *head;
    while (c) {
        if (c->k == k) {
            if (v != -1) c->v = v;
            if (c != *head) {
                if (c->n) c->n->p = c->p; else *tail = c->p;
                c->p->n = c->n;
                c->n = *head; c->p = NULL;
                (*head)->p = c; *head = c;
            }
            return c->v;
        }
        c = c->n;
    }
    if (v == -1) return -1;
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->k = k; nn->v = v; nn->n = *head; nn->p = NULL;
    if (*head) (*head)->p = nn;
    *head = nn;
    if (!*tail) *tail = nn;
    if (++(*sz) > cap) {
        struct node *tmp = *tail;
        *tail = tmp->p;
        (*tail)->n = NULL;
        free(tmp);
        (*sz)--;
    }
    return v;
}