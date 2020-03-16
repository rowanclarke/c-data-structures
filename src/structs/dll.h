#ifndef DOUBLE_LINKED_LIST

#define DOUBLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct doubleNode {
	struct doubleNode *p; 	// point to previous node
    struct doubleNode *n; 	// point to next node
	void *v;
} doubleNode;

typedef struct doubleLinkedList {
    struct doubleNode *h; 	// point to head node
	int s;					// size of linked list
} doubleLinkedList;

node* initNode(void *v) {
	node *n = malloc(sizeof(node));
	n->n = v;
	return n;
}

void initDouble(linkedList *ll, node *h) {
	ll->h = h;
	ll->s = 1;
}

void addAfterDouble(doubleLinkedList *dll, doubleNode *b, doubleNode *n) {
    n->p = b;
	n->n = b->n;
    b->n = n;
    if (n->n) n->n->p = n;
    dll->s++;
}

void removeDouble(doubleLinkedList *dll, doubleNode *n) {
    n->p->n = n->n;
    n->n->p = n->p;
    free(n);
    dll->s--;
}

void printDouble(doubleLinkedList *dll, void (*f)(void*)) {
	doubleNode *p;
	int i;
    p = dll->h;
    printf("size: %d\n", dll->s);
    for (i = 0; i < dll->s; i++) {
        (*f)(p->v);
        printf("%s", i < dll->s-1 ? "<->" : "\n");
        p = p->n;
    }
}

#endif
