#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum precedence {
	NONE = 0, IMPORTANT = 1, URGENT = 2
} Precedence;

typedef struct item {
	char desc[50];
	double timeToComplete;
	Precedence precedence;

} Item;

typedef struct node {
	Item item;
	struct node *pNext;
	struct node *pPrev;
} Node;

void initList(Node **listPtr);

Node* newNode(Item newItem);

void printListL2R(Node *listPtr);

void printListR2L(Node *listPtr);

int prepend(Node **listPtr, Item newItem);

int append(Node **listPtr, Item newItem);

int getLength(Node *listPtr, int startIdx);

Node* getElementAtIndex(Node **listPtr, int searchIdx);

void fisherYatesShuffle(Node **listPtr);

void debugPtr(Node *listPtr);
