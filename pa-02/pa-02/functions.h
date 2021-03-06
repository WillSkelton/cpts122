#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef enum rating {
	NONE = 0, ONESTAR = 1, TWOSTAR = 2, THREESTAR = 3, FOURSTAR = 4, FIVESTAR = 5
} Rating;

typedef struct duration {
	int min;
	int sec;
} Duration;

typedef struct record {
	char artist[30];
	char album[30];
	char song[30];
	char genre[15];
	Duration duration;
	int timesPlayed;
	Rating rating;
	unsigned long id;

} Record;

typedef struct node {
	Record record;
	struct node *pNext;
	struct node *pPrev;
} Node;

typedef struct list {
	Node *head;
	Node *tail;
	
	int length;


} List;

void initList(List *l);

void newRecord(Record *r, char artist[30], char album[30], char song[30], char genre[15],
	int minutes, int second, int timesPlayed, Rating rating);

Node* newNode(Record newRecord);

void printListL2R(Node *nodePtr);

void printListR2L(Node *nodePtr);

int prepend(List *list, Record *newRecord);

int append(List *list, Record *newRecord);

int deleteAllByArtist(List *list, char *artistName);

int deleteSong(List *list, Record *record);

int pop(List *list);

int getLength(Node *listPtr, int startIdx);

Node* getElementAtIndex(Node **listPtr, int searchIdx);

void fisherYatesShuffle(Node **listPtr);

void debugPtr(Node *listPtr);

int listCompare(Node *l1, Node *l2);
