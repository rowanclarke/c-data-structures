#ifndef LINKED_LIST

#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *n; // point to next node
	void *v;		// value
} node;

typedef struct linkedList {
    struct node *h; // point to first node
	int s;			// size
} linkedList;

node* initNode(void *v);
void initLinkedList(linkedList *ll, node *h);
void addAfter(linkedList *ll, node *b, node *n);
void removeAfter(linkedList *ll, node *b);
void removeLast(linkedList *ll);
void removeAt(linkedList *ll, int n);
void printLinkedList(linkedList *ll, void (*f)(void*));

node* initNode(void *v) {
	node *n = malloc(sizeof(node));
	n->v = v;
	return n;
}

void initLinkedList(linkedList *ll, node *h) {
	ll->h = h;
	ll->s = 1;
}

void addAfter(linkedList *ll, node *b, node *n) {
    n->n = b->n;
    b->n = n;
    ll->s++;
}

void removeAfter(linkedList *ll, node *b) {
    node *tmp;
    tmp = b->n->n;
    free(b->n);
    b->n = tmp;
    ll->s--;
}

void removeAt(linkedList *ll, int n) {
	if (n == 0) {
		node *tmp;
	    tmp = ll->h->n;
	    free(ll->h);
		ll->h = tmp;
		ll->s--;
	} else {
		node *p;
		int i;
		p = ll->h;
		for (i = 0; i < n-1; i++) p = p->n;
	    removeAfter(ll, p);
	}
}

void printLinkedList(linkedList *ll, void (*f)(void*)) {
    node *p;
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
