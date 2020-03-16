#ifndef STACK

#define STACK

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    void **p;        // current pointer
} stack;

void initStack(stack *s, int l);
void push(stack *s, void *n);
void pop(stack *s);
void printStack(stack *s, void (*f)(void*));

void initStack(stack *s, int l) {
	s->p = calloc(l, sizeof(void*));	
}

void push(stack *s, void *n) {
    s->p++;
    *s->p = n;
}

void pop(stack *s) {
    free(*s->p);
    s->p--;
}

void printStack(stack *s, void (*f)(void*)) {
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
