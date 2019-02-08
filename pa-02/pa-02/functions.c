#include "functions.h"

void initList(List *l) {
	l->head = NULL;
	l->tail = NULL;
	l->length = 0;
}

void newRecord(Record *r, char artist[30], char album[30], char song[30], char genre[15], 
	int minutes, int seconds, int timesPlayed, Rating rating) {

	static unsigned long id = 0;

	strcpy(r->artist, artist);
	strcpy(r->album, album);
	strcpy(r->song, song);
	strcpy(r->genre, genre);
	
	Duration d = { minutes, seconds };
	r->duration = d;
	r->timesPlayed = timesPlayed;
	r->rating = rating;
	r->id = id;

	++id;

}

Node* newNode(Record newRecord) {

	Node *tempPtr = NULL;

	tempPtr = (Node *)malloc(sizeof(Node));

	if (tempPtr != NULL) {
		tempPtr->record = newRecord;
		tempPtr->pNext = NULL;
		tempPtr->pPrev = NULL;

	}

	return tempPtr;
}

void printListL2R(Node *nodePtr) {
	printf("---> ");

	if (nodePtr != NULL) {

		printf("\"%s\" ", nodePtr->record.song);
		printListL2R(nodePtr->pNext);
	}
}

void printListR2L(Node *nodePtr) {

	if (nodePtr != NULL) {
		
		printListR2L(nodePtr->pNext);
		printf("<--- ");
		printf("\"%s\" ", nodePtr->record.song);
	}

	//printf("\n");

}

int prepend(List *list, Record *newRecord) {
	
	Node *tempPtr = NULL;
	int success = 0;
	

	tempPtr = newNode(*newRecord);

	if (tempPtr != NULL) {
		success = 1;

		if (list->head != NULL) {
			list->head->pPrev = tempPtr;
		}
		else {
			list->tail = tempPtr;
		}
		
		tempPtr->pNext = list->head;

		list->head = tempPtr;

		list->length++;

	}
	
	return success;
}

int append(List *list, Record *newRecord) {

	Node *tempPtr = NULL;
	Node *curNode = NULL;
	Node *prevNode = NULL;

	int success = 0;

	tempPtr = newNode(*newRecord);
	
	if (tempPtr != NULL) {

		success = 1;

		list->tail->pNext = tempPtr;
		list->tail = tempPtr;

		list->length++;
	}

	
	return success; 
}

int pop(List *list) {
	int success = 0;

	if (list != NULL && list->head != NULL) {
		
		int success = 1;
		Node *tempPtr = list->head;

		list->head = list->head->pNext;

		free(tempPtr);
	}

	return success;
}

int deleteAtIndex(List *list, int idx) {
	int success = 0;

	return success;
}

int deleteItem(List *list, Record *record) {
	int success = 0;

	Node *tempNext = NULL;
	Node *tempPrev = NULL;
	
	Node *compare = list->head;

	for (int i = 0; i < list->length; ++i) {
		if (compare->record.id == record->id) {
			break;
		}
		else {
			compare = compare->pNext;

			tempNext = compare->pNext;
			tempPrev = compare->pPrev;
		}
	}

	if (tempNext != NULL) tempNext->pPrev = tempPrev;

	if (tempPrev != NULL) tempPrev->pNext = tempNext;

	if (record->id == list->head->record.id) {
		list->head = list->head->pNext;
	}
	
	if (record->id == list->tail->record.id) {
		list->tail = list->tail->pPrev;
	}

	free(compare);

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

		//printf("%s\n", iterator->record.artist);


		iterator = iterator->pNext;
	}

}

void debugPtr(Node *listPtr) {

	if (listPtr != NULL) {
		printf("%s --> ", listPtr->record.artist);
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
	else if (strcmp(l1->record.artist, l2->record.artist) == 0) {
		++idx;
		same = listCompare(l1->pNext, l2->pNext);
	
	}
	else {
		same = -2;
	}

	return same;
}