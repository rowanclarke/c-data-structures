#ifndef STACK_H

#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct STACK {
    void **p;        // current pointer
} STACK, *PSTACK;

void initStack(PSTACK s, int l);
void push(PSTACK s, void *n);
void pop(PSTACK s);
void printSTACK(PSTACK s, void (*f)(void*));

void initStack(PSTACK s, int l) {
	s->p = calloc(l, sizeof(void*));
}

void push(PSTACK s, void *n) {
    s->p++;
    *s->p = n;
}

void pop(PSTACK s) {
    free(*s->p);
    s->p--;
}

void printSTACK(PSTACK s, void (*f)(void*)) {
	void **p;
	p = s->p;
    while (*p) {
        (*f)(*p);
        printf("\n");
        p--;
    }
    printf("\n");
}

#endif
