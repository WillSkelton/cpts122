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
	printf("---> ");

	if (listPtr != NULL) {

		printf("%s ", listPtr->item.desc);
		printListL2R(listPtr->pNext);
	}
}

void printListR2L(Node *listPtr) {

	if (listPtr != NULL) {
		
		printListR2L(listPtr->pNext);
		printf("<--- ");
		printf("%s ", listPtr->item.desc);
	}

	//printf("\n");

}

int prepend(Node **listPtr, Item newItem) {
	
	Node *tempPtr = NULL;
	int success = 0;
	

	tempPtr = newNode(newItem);

	if (tempPtr != NULL) {
		success = 1;

		if (*listPtr != NULL) {
			(*listPtr)->pPrev = tempPtr;
		}
		
		tempPtr->pNext = *listPtr;

		*listPtr = tempPtr;

	}

	return success;
}

int append(Node **listPtr, Item newItem) {

	Node *tempPtr = NULL;
	Node *curNode = NULL;
	Node *prevNode = NULL;

	int success = 0;

	tempPtr = newNode(newItem);
		
	if (tempPtr != NULL) {
		success = 1;

		curNode = *listPtr;

		while (curNode->pNext != NULL) {
			curNode = curNode->pNext;
		}

		if (*listPtr != NULL) {
			tempPtr->pPrev = curNode;
		}

		tempPtr->pNext = NULL;
		curNode->pNext = tempPtr;
	}

	return success;
}
