#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	double value;
} Data;

typedef struct node {
	Data data;
	struct node *pNext;
}Node;

typedef struct stack {
	int length;
	char name;
	Node *pTop;
} Stack;

Node *newNode(Data *item);

void newStack(Stack *s);

int isEmpty(Stack *s);

double push(Stack *s, Data *item);

double batchPush(Stack *s, Data *item[], int length);

int pop(Stack *s);

int batchPop(Stack *s, int numToPop);

int peek(Stack *s);

void hanoi(Stack *src, Stack *dest, Stack *aux, int n);

