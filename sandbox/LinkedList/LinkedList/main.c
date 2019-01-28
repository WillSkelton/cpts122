#include "functions.h"


int main(void) {

	Node *ToDo;
	Node *empty;

	initList(&ToDo);
	initList(&empty);

	Item item0 = {"0", 0.25, 3};
	Item item1 = {"1", 1.5, 1};
	Item item2 = { "2", 4, 2 };
	Item item3 = { "3", 3, 0 };

	append(&ToDo, item1);
	append(&ToDo, item2);
	append(&ToDo, item3);
	append(&ToDo, item0);


	printListL2R(ToDo);
	printf("\n");
	printListR2L(ToDo);
	printf("\n");

	printf("ToDo Length: %d\n", getLength(ToDo, 0));

	//printf("empty Length: %d\n", getLength(empty, 0));

	
	return 0;
}