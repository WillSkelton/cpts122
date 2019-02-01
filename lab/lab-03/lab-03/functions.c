#include "functions.h"

Node *newNode(Data *item) {
	
	Node *tempPtr = (Node*) malloc(sizeof(Node));
	
	tempPtr->data = *item;

	return tempPtr;
}

void newStack(Stack *s) {
	s->length = 0;
	s->pTop = NULL;
	s->name = ' ';
}

int isEmpty(Stack *s) {
	int empty = (s->pTop == NULL) ? 1 : 0;

	return empty;
}

double push(Stack *s, Data *item) {

	Node *tempPtr = newNode(item);

	tempPtr->pNext = s->pTop;

	s->pTop = tempPtr;

	s->length++;
	return item->value;
}

double batchPush(Stack *s, Data *item[], int length) {

	for (int i = 0; i < length; ++i) {
		push(s, item[i]);
	}
}


int pop(Stack *s){

	int isNowEmpty = 0;

	Node *temp = s->pTop->pNext;

	free(s->pTop);

	s->pTop = temp;

	isNowEmpty = (s->pTop == NULL) ? 1 : 0;

	s->length--;
	return isNowEmpty;
}

int batchPop(Stack *s, int numToPop) {
	
	int success = (s->length <=numToPop) ? 1 : 0;

	if (success == 1) {
		for (int idx = 0; idx < numToPop; ++idx) {
			pop(s);
		}
	}

	return success;
}

int peek(Stack *s) {
	
	int empty = isEmpty(s);

	if (empty == 0) {
		printf("Stack is %d units tall. Top Element: %.2lf\n", s->length, s->pTop->data.value);
	}
	else {
		printf("There's nothing in the stack.\n");
	}
	

	return empty;
}

void hanoi(Stack *src, Stack *dest, Stack *aux, int n) {
	if (n == 1) {
		printf("\n Move disk 1 from %c to rod %c.", src->name, dest->name);
		push(dest, src->pTop);
		pop(src);
		return;
	}
	
	hanoi(src, aux, dest, n - 1);
	printf("\n Move disk %d from %c to rod %c.", n, src->name, dest->name);
	push(dest, src->pTop);
	pop(src);

	hanoi(aux, dest, src, n - 1);
}