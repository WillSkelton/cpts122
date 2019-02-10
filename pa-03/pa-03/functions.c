#include "functions.h"

void menuREPL(void) {
	List playlist;
	initList(&playlist);

	int choice = -1;
	
	do {
		system("cls");
		choice = inputCheck(1, 11, printMenu);
		
		//choice = 1;

		switch (choice) {
		case 1:
			load(&playlist);
			system("pause");
			break;

		case 2:
			store();
			break;

		case 3:
			display();
			break;

		case 4:
			insert();
			break;

		case 5:
			delete();
			break;

		case 6:
			edit();
			break;

		case 7:
			sort();
			break;

		case 8:
			rate();
			break;
		case 9:
			play();
			break;

		case 10:
			shuffle();
			break;

		case 11:
			exit();
			break;
		}

	} while (choice != 11);
}

int getUserInput(void) {

}

void printBorder(int size, int length) {

	switch (size) {
	case 1:
		for (int i = 0; i < length; ++i) {
			printf("-");
		}
		printf("\n");
		break;
	case 2:
		for (int i = 0; i < length; ++i) {
			printf("=");
		}
		printf("\n");
		break;
	}

}

int inputCheck(int lowerBound, int upperBound, void(*printMenu)()) {
	int choice = 0;
	do {
		choice = 0;

		printMenu();
		scanf("%d", &choice);

		if (choice < lowerBound || choice > upperBound) {
			system("cls");
			printBorder(2, 45);
			printf("%d? That's not a valid option. Try again.\n", choice);
			printBorder(2, 45);
		}
		else {
			break;
		}

	} while (choice != upperBound);

	return choice;
}

void printMessage(char *message) {

	int length = strlen(message) + 6;

	printBorder(2, length);
	printf("|| %s ||\n", message);
	printBorder(2, length);
}

void printMenu(void) {
	printf("1. ) Load\n");
	printf("2. ) Store\n");
	printf("3. ) Display\n");
	printf("4. ) Insert\n");
	printf("5. ) Delete\n");
	printf("6. ) Edit\n");
	printf("7. ) Sort\n");
	printf("8. ) Rate\n");
	printf("9. ) Play\n");
	printf("10.) Shuffle\n");
	printf("11.) Exit\n");
	printf(">>> ");
}

void load(List *playlist) {

	FILE *infile = fopen("music.csv", "r");

	Record tempRecord;
	char artist[30];
	char album[30];
	char song[30];
	char genre[15];
	int minutes = 0;
	int seconds = 0;
	int timesPlayed = 0;
	Rating rating;

	char firstChar = ' ';
	char *token = NULL;
	char line[100];



	do {

		firstChar = getc(infile);

		if (firstChar == EOF) {
			break;
		}

		line[0] = firstChar;

		fgets(&line[1], 100, infile);

		// Get Artist Name
		if (firstChar == '\"') {

			// Clear "s
			token = strtok(line, "\"");

			// move name into placeholder
			strcpy(artist, token);

			// Skip to next item
			token = strtok(NULL, "");

		}
		else {
			// Get Name
			token = strtok(line, ",");

			// move name into placeholder
			strcpy(artist, token);

			// Skip to next item
			token = strtok(NULL, "");
		}

		// Get Album
		strcpy(line, token);
		token = strtok(line, ",");
		strcpy(album, token);
		token = strtok(NULL, "");

		// Get Song Name
		strcpy(line, token);
		token = strtok(line, ",");
		strcpy(song, token);
		token = strtok(NULL, "");

		// Get Genre
		strcpy(line, token);
		token = strtok(line, ",");
		strcpy(genre, token);
		token = strtok(NULL, "");

		// Get Minutes
		strcpy(line, token);
		token = strtok(line, ":");
		minutes = atoi(line);
		token = strtok(NULL, "");

		// Get Seconds
		strcpy(line, token);
		token = strtok(line, ",");
		seconds = atoi(line);
		token = strtok(NULL, "");

		// Get Times Played
		strcpy(line, token);
		token = strtok(line, ",");
		timesPlayed = atoi(line);
		token = strtok(NULL, "");

		// Get Rating
		strcpy(line, token);
		token = strtok(line, ",");
		rating = atoi(line);
		token = strtok(NULL, "");

		newRecord(&tempRecord, artist, album, song, genre, minutes, seconds, timesPlayed, rating);

		append(playlist, &tempRecord);


	} while (firstChar != EOF);

}

void store(void) {

}

void display(void) {

}

void insert(void) {

}

void delete(void) {

}

void edit(void) {

}

void sort(void) {

}

void rate(void) {

}

void play(void) {

}

void shuffle(void) {

}

void exit(void) {

}

void test(void) {
	List list;

	initList(&list);

	Record test1;

	newRecord(&test1, "Black Keys", "Attack and Release", "All You Ever Wanted", "Blues", 2, 56, 200, 5);

	//newRecord(&test1, "Black Keys",	"Attack and Release", "All You Ever Wanted", "Blues", {2, 56 }, 200, 5);

	Record test2;
	newRecord(&test2, "Black Keys", "Attack and Release", "I Got Mine", "Blues", 3, 59, 500, 5);

	Record test3;
	newRecord(&test3, "Electric Six", "Fire", "Formula 409", "Rock", 3, 59, 700, 5);


	append(&list, &test1);
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


}