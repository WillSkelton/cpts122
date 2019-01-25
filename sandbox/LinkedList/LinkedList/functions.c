#include "functions.h"

void initList(Node **listPtr) {
	*listPtr = NULL;

}

Node* newNode(Item newItem) {

	Node *tempPtr = NULL;

	tempPtr = (Node *)malloc(sizeof(Node));

	if (tempPtr != NULL) {
		tempPtr->item = newItem;
		tempPtr->pNext = NULL;
		tempPtr->pPrev = NULL;
	}

	return tempPtr;
}

void printListL2R(Node *listPtr) {
	
	while (listPtr->pNext != NULL) {
		printf("---> %s ", listPtr->item.desc);
	}

}

int prepend(Node **listPtr, Item newItem) {
	
	Node *tempPtr = NULL;
	int success = 0;
	

	tempPtr = newNode(newItem);

	if (tempPtr != NULL) {
		success = 1;

		(*listPtr)->pPrev = tempPtr;

		tempPtr->pNext = *listPtr;
		*listPtr = tempPtr;

	}

	return success;
}

