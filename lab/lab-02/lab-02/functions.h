#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef enum boolean {
	FALSE, TRUE
} Boolean;

typedef struct contact {
	char name[50];
	char phone[12]; // 18005557577
	char email[50];
	char title[20];
} Contact;

typedef struct node {
	Contact data;

	struct node *pNext;
} Node;

void initList(Node **pList);

Node *makeNode(Contact c);

int insertAtFront(Node **listPtr, Contact newContact);

void printListRec(Node *listPtr);

int deleteNodeRec(Node **nodePtr, Node **prevNode, Contact search);