#include "functions.h"

int main(void) {

	List list;

	initList(&list);

	Record test1;
	
	newRecord(&test1, "Black Keys",	"Attack and Release", "All You Ever Wanted", "Blues", 2, 56, 200, 5);

	//newRecord(&test1, "Black Keys",	"Attack and Release", "All You Ever Wanted", "Blues", {2, 56 }, 200, 5);

	Record test2;
	newRecord(&test2, "Black Keys", "Attack and Release", "I Got Mine", "Blues", 3, 59, 500, 5);

	Record test3;
	newRecord(&test3, "Electric Six", "Fire", "Formula 409", "Rock", 3, 59, 700, 5);


	prepend(&list, &test1);
	//printListL2R(list.head);

	//printf("\n");

	prepend(&list, &test2);
	//printListL2R(list.head);

	printf("Before:\n");

	prepend(&list, &test3);
	printListL2R(list.head);

	printf("\nAfter:\n");

	deleteAllByArtist(&list, "Black Keys");
	printListL2R(list.head);

	printf("\n");


	return 0;
}