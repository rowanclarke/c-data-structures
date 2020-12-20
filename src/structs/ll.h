#ifndef LINKED_LIST_H

#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct PNODE n; // point to next NODE
	void *v;		// value
} NODE, *PNODE;

typedef struct LLIST {
    struct PNODE h; // point to first NODE
	int s;			// size
} LLIST, *PLLIST;

PNODE initNode(void *v);
void initList(PLLIST ll, PNODE h);
void addAfterList(PLLIST ll, PNODE b, PNODE n);
void removeAfterList(PLLIST ll, PNODE b);
void removeAtList(PLLIST ll, int n);
void printList(PLLIST ll, void (*f)(void*));

PNODE initNode(void *v) {
	PNODE n = malloc(sizeof(NODE));
	n->v = v;
	return n;
}

void initList(PLLIST ll, PNODE h) {
	ll->h = h;
	ll->s = 1;
}

void addAfterList(PLLIST ll, PNODE b, PNODE n) {
    n->n = b->n;
    b->n = n;
    ll->s++;
}

void removeAfterList(PLLIST ll, PNODE b) {
    PNODE tmp;
    tmp = b->n->n;
    free(b->n);
    b->n = tmp;
    ll->s--;
}

void removeAtList(PLLIST ll, int n) {
	if (n == 0) {
		PNODE tmp;
	    tmp = ll->h->n;
	    free(ll->h);
		ll->h = tmp;
		ll->s--;
	} else {
		PNODE p;
		int i;
		p = ll->h;
		for (i = 0; i < n-1; i++) p = p->n;
	    removeAfter(ll, p);
	}
}

void printList(PLLIST ll, void (*f)(void*)) {
    PNODE p;
    int i;
	p = ll->h;
    printf("size: %d\n", ll->s);
    for (i = 0; i < ll->s; i++) {
        (*f)(p->v);
        printf("%s", i<ll->s-1 ? "->" : "\n");
        p = p->n;
    }
}

#endif
