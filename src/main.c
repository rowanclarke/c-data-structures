#include "structs/ll.h"

typedef struct person {
    char* f; // firstname
    char* s; // lastname
} person;

void printPerson(person* p) {
    printf("{%s %s}", p->f, p->s);
}

person* initPerson(char* f, char* s) {
    person* p = malloc(sizeof(person));
    p->f = f;
    p->s = s;
    return p;
}

int main(int argc, char** argv) {
	
	/* // CIRCULAR QUEUE:
	queue q;
    initQueue(&q, 5);
	enqueue(&q, initPerson("A", "A"));
    printQueue(&q, (void*) printPerson);
	enqueue(&q, initPerson("B", "B"));
	printQueue(&q, (void*) printPerson);
	dequeue(&q);
	printQueue(&q, (void*) printPerson);*/
    
	/* // STACK
	stack s;
	initStack(&s, 5);
	printStack(&s, (void*) printPerson);
	push(&s, initPerson("A", "A"));
	printStack(&s, (void*) printPerson);
	push(&s, initPerson("B", "B"));
	printStack(&s, (void*) printPerson);
	push(&s, initPerson("C", "C"));
	printStack(&s, (void*) printPerson);
	push(&s, initPerson("D", "D"));
	printStack(&s, (void*) printPerson);
	pop(&s);
	printStack(&s, (void*) printPerson);
	pop(&s);
	printStack(&s, (void*) printPerson);
	pop(&s);
	printStack(&s, (void*) printPerson);
	pop(&s);
	printStack(&s, (void*) printPerson);*/
	
	/* // LINKED LIST
	linkedList ll;
	node *n = initNode(initPerson("A", "A"));
	initLinkedList(&ll, n);
	addAfter(&ll, n, initNode(initPerson("B", "B")));
	printLinkedList(&ll, (void*) printPerson);*/
	
	// DOUBLE LINKED LIST
	
	return 0;
}
