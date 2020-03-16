#ifndef CIRCULAR_QUEUE

#define CIRCULAR_QUEUE

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    void **f;           // front
    void **b;           // back
    void **s;           // start
    void **e;           // end
} queue;

void initQueue(queue* q, int s);
void enqueue(queue *q, void *n);
void dequeue(queue *q);

void initQueue(queue* q, int s) {
    q->s = calloc(s, sizeof(void*));
    q->e = q->s+s;
    q->f = q->s;
    q->b = q->s-1;
}

void enqueue(queue *q, void *n) {
    if ((q->b+1) == q->e) q->b=q->s;
    else q->b++;
    *q->b = n;
}

void dequeue(queue *q) {
    free(*q->f);
    if ((q->f+1) == q->e) q->f=q->s;
    else q->f++;
}

void printQueue(queue *q, void (*f)(void*)) {
    void **p;
    p = q->f;
    while (p != q->b) {
        (*f)(*p);
        printf(">");
        if (p+1 == q->e) p=q->s;
        else p++;
    }
    (*f)(*p);
    printf("\n");
}

#endif
