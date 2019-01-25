#include "functions.h"


int main(void) {

	Node *ToDo;

	initList(&ToDo);

	Item item1 = {"Wash Dog", 1.5, 1};
	Item item2 = { "Math Homework", 4, 2 };
	Item item3 = { "Watch TV", 3, 0 };

	prepend(&ToDo, item1);
	prepend(&ToDo, item2);
	prepend(&ToDo, item3);

	printListL2R(ToDo);

	return 0;
}