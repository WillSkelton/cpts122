#include "functions.h"

int main(void) {
	
	Node *ptrToHeadNode;

	Contact dude1 = { "dude1", "18005557577", "dude1@email.com", "CEO" };
	Contact dude2 = { "dude2", "18005557577", "dude2@email.com", "CEO" };
	Contact dude3 = { "dude3", "18005557577", "dude3@email.com", "CEO" };
	Contact dude4 = { "dude4", "18005557577", "dude4@email.com", "CEO" };



	initList(&ptrToHeadNode);
	insertAtFront(&ptrToHeadNode, dude1);
	insertAtFront(&ptrToHeadNode, dude2);
	insertAtFront(&ptrToHeadNode, dude3);
	insertAtFront(&ptrToHeadNode, dude4);


	printListRec(ptrToHeadNode);
	putchar('\n');
		
	deleteNodeRec(&ptrToHeadNode, NULL, dude3);

	printListRec(ptrToHeadNode);
	putchar('\n');

	deleteNodeRec(&ptrToHeadNode, NULL, dude1);

	printListRec(ptrToHeadNode);
	putchar('\n');
	return 0;

}