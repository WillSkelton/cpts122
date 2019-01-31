#include "functions.h"


int main(void) {

	srand((unsigned int)time(NULL));

	Node *ToDo;
	Node *empty;

	initList(&ToDo);
	initList(&empty);

	Item item0 = { "1", 0.25, 3};
	Item item1 = { "2", 1.5, 1};
	Item item2 = { "3", 4, 2 };
	Item item3 = { "4", 3, 0 };

	Item item4 = { "5", 0.25, 3 };
	Item item5 = { "6", 1.5, 1 };
	Item item6 = { "7", 4, 2 };
	Item item7 = { "8", 3, 0 };

	prepend(&ToDo, item0);
	prepend(&ToDo, item1);
	prepend(&ToDo, item2);
	prepend(&ToDo, item3);

	prepend(&ToDo, item4);
	prepend(&ToDo, item5);
	prepend(&ToDo, item6);
	prepend(&ToDo, item7);


	prepend(&empty, item0);
	prepend(&empty, item1);
	prepend(&empty, item2);
	prepend(&empty, item3);

	prepend(&empty, item4);
	prepend(&empty, item5);
	prepend(&empty, item6);
	//prepend(&empty, item7);

	printf("%d\n", listCompare(ToDo,empty));

	// printf("%s\n", getElementAtIndex(&ToDo, 3)->item.desc);

	//printListL2R(ToDo);
	printf("\n");
	
	fisherYatesShuffle(&ToDo);

	printListL2R(ToDo);
	printf("\n");
	
	return 0;
}