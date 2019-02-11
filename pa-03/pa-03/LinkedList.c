#include "LinkedList.h"

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

void printListTop2Bottom(Node *nodePtr) {
	printf("-> ");

	if (nodePtr != NULL) {

		if (strstr(nodePtr->record.artist, ", ") != NULL) {
			printf("\"%s\",", nodePtr->record.artist);
		}
		else {
			printf(" %s,", nodePtr->record.artist);
		}

		printf("%s,", nodePtr->record.album);
		printf("%s,", nodePtr->record.song);
		printf("%s,", nodePtr->record.genre);
		printf("%d:%d,", nodePtr->record.duration.min, nodePtr->record.duration.sec);
		printf("%d,", nodePtr->record.timesPlayed);
		printf("%d\n", nodePtr->record.rating);

		printListTop2Bottom(nodePtr->pNext);
		
	}
}

int printAllByArtist(Node *nodePtr, char *artist) {

	int numResults= 0;
	char *token = NULL;
	char temp[30];

	if (nodePtr != NULL) {

		strcpy(temp, nodePtr->record.artist);
		// token = strtok(temp, ",");

		if (strcmp(artist, nodePtr->record.artist) == 0) {
			numResults = 1;
			printf("-> Song ID: %d | ", nodePtr->record.id);


			if (strstr(nodePtr->record.artist, ", ") != NULL) {
				printf("\"%s\",", nodePtr->record.artist);
			}
			else {
				printf(" %s,", nodePtr->record.artist);
			}

			printf("%s,", nodePtr->record.album);
			printf("%s,", nodePtr->record.song);
			printf("%s,", nodePtr->record.genre);
			printf("%d:%d,", nodePtr->record.duration.min, nodePtr->record.duration.sec);
			printf("%d,", nodePtr->record.timesPlayed);
			printf("%d\n", nodePtr->record.rating);

		}

		numResults += printAllByArtist(nodePtr->pNext, artist);

	}

	return numResults;
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
		
		if (list->tail != NULL) {
			list->tail->pNext = tempPtr;
		}
		else {
			list->head = tempPtr;
		}
		
		
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

int deleteAllByArtist(List *list, char *artistName) {
	int success = 0;
	int isMatch = 0;

	unsigned int numberDeleted = 0;

	Node *tempNext = NULL;
	Node *tempPrev = NULL;

	Node *compare = (list->head != NULL) ? list->head : NULL;
	Node *temp = NULL;

	if (compare != NULL) {
		success = -1;

		for (int i = 0; i < list->length; ++i) {
			
			isMatch = strcmp(artistName, compare->record.artist);

			if (isMatch == 0) {
				success = 1;

				// Relink backwards
				if (tempNext != NULL) tempNext->pPrev = tempPrev;

				// Relink Forwards
				if (tempPrev != NULL) tempPrev->pNext = tempNext;

				// Readjust Head if neccesary
				if (compare->record.id == list->head->record.id) {
					list->head = list->head->pNext;
				}

				// Readjust Tail if neccesary
				if (compare->record.id == list->tail->record.id) {
					list->tail = list->tail->pPrev;
				}

				if (success == 1) {
					// Hold onto next song
					temp = compare->pNext;

					// free deleted song from heap
					free(compare);

					// Adjust list length
					++numberDeleted;
				}
				// move onto next song
				compare = temp;
		
				// Keep track of songs on either side
				tempNext = (compare != NULL) ? compare->pNext : NULL;
				tempPrev = (compare != NULL) ? compare->pPrev : NULL;
			}
			else {

				// move on
				compare = compare->pNext;

				tempNext = (compare != NULL) ? compare->pNext : NULL;
				tempPrev = (compare != NULL) ? compare->pPrev : NULL;

			}
		}
	}

	list->length -= numberDeleted;

	return success;
}

Node* findByID(List *list, unsigned long id) {
	Node *tempNode = NULL;

	if (list->head != NULL) {
		tempNode = list->head;
		for (int i = 0; i < list->length; ++i) {
			if (tempNode->record.id == id) {
				break;
			}
			else {
				tempNode = tempNode->pNext;
			}
		}
	}

	return tempNode;
}

int deleteSong(List *list, Record *record) {
	int success = 0;

	Node *tempNext = NULL;
	Node *tempPrev = NULL;
	
	Node *compare = list->head;

	for (int i = 0; i < list->length; ++i) {
		if (compare->record.id == record->id) {
			success = 1;
			break;
		}
		else {
			compare = compare->pNext;

			tempNext = (compare != NULL) ? compare->pNext : NULL;
			tempPrev = (compare != NULL) ? compare->pPrev : NULL;
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

	if (success == 1) {
		free(compare);
		list->length--;
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

void willSkeltonPoppinHopper(List *list) {
	Node *iterator = NULL;
	Node *startPtr = NULL;
	Node *swapPtr = NULL;
	Node *temp = NULL;
	Node *shuffled;
	initList(&shuffled);

	int idx = 0, length = list->length, randoCalrissian = 0;


	iterator = list->head;


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