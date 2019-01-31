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

		while ((curNode != NULL) && (curNode->pNext != NULL)) {
			curNode = curNode->pNext;
		}

		if (*listPtr != NULL) {
			tempPtr->pPrev = curNode;

			tempPtr->pNext = NULL;
			curNode->pNext = tempPtr;
		}
		else {
			*listPtr = tempPtr;
		}

		
	}

	return success; 
}

int getLength(Node *listPtr, int startIdx) {

	int tempIdx = startIdx;;

	if (listPtr != NULL) {
		tempIdx = getLength(listPtr->pNext, tempIdx + 1);
	}
	

	return tempIdx;
}

Node* getElementAtIndex(Node **listPtr, int searchIdx) {
	int curIdx = 0;
	Node *found = NULL;
	
	found = *listPtr;

	while ((found != NULL) && (found->pNext != NULL)) {

		if (curIdx == searchIdx) {
			break;
		}

		found = found->pNext;

		++curIdx;
	}

	return found;

}

void fisherYatesShuffle(Node **listPtr) {
	Node *iterator = NULL;
	Node *startPtr = NULL;
	Node *swapPtr = NULL;
	Node *temp = NULL;
	Node *shuffled;
	initList(&shuffled);

	int idx = 0, length = getLength(*listPtr, 0), randoCalrissian = 0;


	iterator = *listPtr;

	for (idx = 0; idx < length; ++idx) {
		randoCalrissian = rand() % length - idx;

		//printf("%s\n", iterator->item.desc);


		iterator = iterator->pNext;
	}

}

void debugPtr(Node *listPtr) {

	if (listPtr != NULL) {
		printf("%s --> ", listPtr->item.desc);
		debugPtr(listPtr->pNext);
	}

}


int listCompare(Node *l1, Node *l2) {
	static int idx = 1;
	int same = 0;

	if ((l1->pNext == NULL) && (l2->pNext != NULL)) {
		same = -1;
	}
	else if ((l2->pNext == NULL) && (l1->pNext != NULL)) {
		same = 1;
	}
	else if (strcmp(l1->item.desc, l2->item.desc) == 0) {
		++idx;
		same = listCompare(l1->pNext, l2->pNext);
	
	}
	else {
		same = -2;
	}

	return same;
}