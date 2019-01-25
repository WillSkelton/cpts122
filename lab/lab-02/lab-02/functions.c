#include "functions.h"

void initList(Node **pList) {
	*pList = NULL;
}

Node *makeNode(Contact contact) {
	Node *tempMemPtr = NULL;

	tempMemPtr = (Node *)malloc(sizeof(Node));

	if (tempMemPtr != NULL) {
		tempMemPtr->data = contact;
		tempMemPtr->pNext = NULL;
	}

	return tempMemPtr;
}

int insertAtFront(Node **listPtr, Contact newContact) {
	Node *tempMemPtr = NULL;
	int success = 0;

	tempMemPtr = makeNode(newContact);

	if (tempMemPtr != NULL) {
		success = 1;
		tempMemPtr->pNext = *listPtr;
		*listPtr = tempMemPtr;
	}

	return success;
}

void printListRec(Node *listPtr) {
	printf("--> ");
	if (listPtr != NULL) {
		printf("%s ", listPtr->data.name);
		printListRec(listPtr->pNext);
	}
}

int deleteNodeRec(Node **nodePtr, Node **prevNode, Contact search) {
	static int idx = 0;
	char currentName[50];
	// char nextName[50];

	strcpy(currentName, (*nodePtr)->data.name);
	// strcpy(nextName, (*nodePtr)->pNext->data.name);

	Node *next = (*nodePtr)->pNext;
	Node *current = (*nodePtr);

	if (next == NULL) {
		printf("Reached the end of the list.\n");
		
		idx = -1;
		return idx;
	}
	else if ((prevNode == NULL) && (strcmp(currentName, search.name) == 0)) {
		printf("Found '%s' at index: %d\n", search.name, idx);
		
		*nodePtr = ((*nodePtr)->pNext);

		idx = 0;
		return idx;
	}
	else if (strcmp(currentName, search.name) == 0) {
		printf("Found '%s' at index: %d\n", search.name, idx);

		(*prevNode)->pNext = next;

		free(current);

		return idx;
	}
	else {
		++idx;
	}

	// printf("%s\n", cur->data.name);
	// printf("%s\n", (*nodePtr)->data.name);

	deleteNodeRec(&next, &current, search);

	return idx;
}