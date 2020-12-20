#ifndef DOUBLE_LINKED_LIST_H

#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct DNODE {
	struct DNODE *p; 	// point to previous node
    struct DNODE *n; 	// point to next node
	void *v;
} DNODE, *PDNODE;

typedef struct DLLIST {
    struct PDNODE h; 	// point to head node
	int s;			   // size of linked list
} DLLIST, *PDLLIST;

PDNODE initNode(void *v) {
	PDNODE n = malloc(sizeof(DNODE));
	n->n = v;
	return n;
}

void initDList(PDLLIST dll, PDNODE h) {
	ll->h = h;
	ll->s = 1;
}

void addAfterDList(PDLLIST dll, PDNODE b, PDNODE n) {
    n->p = b;
	n->n = b->n;
    b->n = n;
    if (n->n) n->n->p = n;
    dll->s++;
}

void removeAfterDList(PDLLIST dll, PDNODE n) {
    n->p->n = n->n;
    n->n->p = n->p;
    free(n);
    dll->s--;
}

void printDList(PDLLIST dll, void (*f)(void*)) {
	PDNODE p;
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
