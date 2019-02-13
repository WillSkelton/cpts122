#include "functions.h"

void menuREPL(void) {
	List playlist;
	initList(&playlist);

	FILE *infile = NULL;

	int choice = -1;
	
	do {
		system("cls");
		choice = inputCheck(1, 11, printMenu);
		
		//choice = 1;

		switch (choice) {
		case 1:

			infile = fopen("musicPlayList.csv", "r");
			
			//infile = fopen("music.csv", "r");
			if (infile != NULL) {
				load(&playlist, infile);
				
				fclose(infile);
			}
			else {
				printMessage("No Save File yet.");
				system("pause");
			}
			break;
		case 2:
			store(&playlist);
			break;

		case 3:
			infile = fopen("musicPlayList.csv", "r");
			if (infile != NULL && playlist.head != NULL) {
				display(&playlist);
				fclose(infile);	
			}
			else {
				printMessage("No Save File yet.");
			}
			system("pause");
			break;

		case 4:
			insert(&playlist);
			break;

		case 5:
			del(&playlist);
			break;

		case 6:
			edit(&playlist);
			break;

		case 7:
			sort();
			break;

		case 8:
			rate(&playlist);
			break;
		case 9:
			play(&playlist);
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

void load(List *playlist, FILE *infile) {

	Record tempRecord;

	char firstChar = ' ';
	char *token = NULL;
	char line[100];

	if (playlist->head == NULL) {

		do {

			firstChar = getc(infile);

			if (firstChar == EOF) {
				break;
			}

			line[0] = firstChar;

			fgets(&line[1], 100, infile);

			parseLine(&tempRecord, line);

			append(playlist, &tempRecord);


		} while (firstChar != EOF);
	}
}

void parseLine(Node *tempRecord, char line[100]) {

	char artist[30];
	char album[30];
	char song[30];
	char genre[15];
	int minutes = 0;
	int seconds = 0;
	int timesPlayed = 0;
	Rating rating;


	char *token = NULL;

	// Get Artist Name
	if (line[0] == '\"') {

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

	newRecord(tempRecord, artist, album, song, genre, minutes, seconds, timesPlayed, rating);

}

void store(List *playlist) {
	FILE *outfile = fopen("musicPlayList.csv", "w");

	Node *tempNode = playlist->head;

	if (tempNode != NULL) {
	
		for (int i = 0; i < playlist->length; ++i) {
			if (strstr(tempNode->record.artist, ", ") != NULL) {
				fprintf(outfile, "\"%s\",", tempNode->record.artist);
			}
			else {
				fprintf(outfile, "%s,", tempNode->record.artist);
			}

			fprintf(outfile, "%s,", tempNode->record.album);
			fprintf(outfile, "%s,", tempNode->record.song);
			fprintf(outfile, "%s,", tempNode->record.genre);
			fprintf(outfile, "%d:%d,", tempNode->record.duration.min, tempNode->record.duration.sec);
			fprintf(outfile, "%d,", tempNode->record.timesPlayed);
			fprintf(outfile, "%d\n", tempNode->record.rating);
			


			// fprintf(outfile, "\n");
			tempNode = tempNode->pNext;
		}
	
	}

	fclose(outfile);
}

void display(List *playlist) {

	int choice = inputCheck(1, 2, printDisplayOptions);
	char name[30];

	switch (choice) {
	case 1:
		printListTop2Bottom(playlist->head);
		break;

	case 2:

		printf("Please enter Artist's Name as (Last, First) or Only Name (ie RZA):\n");
		printf(">>> ");
		getchar();
		fgets(name, 30, stdin);
		strtok(name, "\n");
		
		printAllByArtist(playlist->head, name);
		break;
	}
	
}

void printDisplayOptions(void) {
	printf("1.) Show All Records\n");
	printf("2.) Show All Records By Artist\n");

}

void insert(List *playlist) {
	char artist[30];
	char album[30];
	char song[30];
	char genre[15];
	int minute = 0;
	int second = 0;
	int timesPlayed = 0;
	Rating rating = 0;

	Record recordToAdd;

	printf("Please enter Artist's new name as (Last, First) or Only Name (ie RZA):\n");
	printf(">>> ");
	getchar();
	fgets(artist, 30, stdin);
	strtok(artist, "\n");
	recordToAdd.artist[0] = ' ';
	strcpy(recordToAdd.artist, artist);
	
	printf("Please enter new album name:\n");
	printf(">>> ");
	getchar();
	fgets(album, 30, stdin);
	strtok(album, "\n");
	strcpy(recordToAdd.album, album);

	printf("Please enter new song name:\n");
	printf(">>> ");
	getchar();
	fgets(song, 30, stdin);
	strtok(song, "\n");
	strcpy(recordToAdd.song, song);
			
	printf("Please enter new genre:\n");
	printf(">>> ");
	getchar();
	fgets(genre, 30, stdin);
	strtok(genre, "\n");
	strcpy(recordToAdd.genre, genre);
	
	printf("Please enter new minutes value:\n");
	printf(">>> ");
	scanf("%d", &minute);
	recordToAdd.duration.min = minute;
	
	printf("Please enter new soconds value:\n");
	printf(">>> ");
	scanf("%d", &second);
	recordToAdd.duration.sec = second;

	printf("Please enter new number of times played:\n");
	printf(">>> ");
	scanf("%d", &timesPlayed);
	recordToAdd.timesPlayed = timesPlayed;
	
	printf("Please enter new rating:\n");
	printf(">>> ");
	scanf("%d", &rating);
	recordToAdd.rating = rating;

	newRecord(&recordToAdd, artist, album, song, genre, minute, second, timesPlayed, rating);

	prepend(playlist, &recordToAdd);
}

void del(List *playlist) {
	Node *songToDelete = NULL;
	Node *song = NULL;

	if (playlist->head != NULL) {
		
		songToDelete = findSongBySongName(playlist);


		deleteSong(playlist, &songToDelete->record);


	}

}

void edit(List *playlist) {

	char name[30];
	char album[30];
	char song[30];
	char genre[15];
	int minute = 0;
	int second = 0;
	int timesPlayed;
	Rating rating;

	int choice = 0;
	Node *songToEdit = findSongByArtist(playlist);

	if (songToEdit != NULL) {
		do {
			choice = inputCheck(1, 9, printAttributes);

			if (choice == 9) {
				break;
			}

			switch (choice) {
			case 1:
				printf("Please enter Artist's new name as (Last, First) or Only Name (ie RZA):\n");
				printf(">>> ");
				getchar();
				fgets(name, 30, stdin);
				strtok(name, "\n");
				strcpy(songToEdit->record.artist, name);
				break;

			case 2:
				printf("Please enter new album name:\n");
				printf(">>> ");
				getchar();
				fgets(album, 30, stdin);
				strtok(album, "\n");
				strcpy(songToEdit->record.album, album);
				break;

			case 3:
				printf("Please enter new song name:\n");
				printf(">>> ");
				getchar();
				fgets(song, 30, stdin);
				strtok(song, "\n");
				strcpy(songToEdit->record.song, song);
				break;

			case 4:
				printf("Please enter new genre:\n");
				printf(">>> ");
				getchar();
				fgets(genre, 30, stdin);
				strtok(genre, "\n");
				strcpy(songToEdit->record.genre, genre);
				break;

			case 5:
				printf("Please enter new minutes value:\n");
				printf(">>> ");
				scanf("%d", &minute);
				songToEdit->record.duration.min = minute;
				break;

			case 6:
				printf("Please enter new soconds value:\n");
				printf(">>> ");
				scanf("%d", &second);
				songToEdit->record.duration.sec = second;
				break;

			case 7:
				printf("Please enter new number of times played:\n");
				printf(">>> ");
				scanf("%d", &timesPlayed);
				songToEdit->record.timesPlayed = timesPlayed;
				break;

			case 8:
				printf("Please enter new rating:\n");
				printf(">>> ");
				scanf("%d", &rating);
				songToEdit->record.rating = rating;
				break;

			case 9:
				break;

			}

		} while (choice != 9);
	}

	system("pause");
}

void printAttributes(void) {
	printf("1.) Artist\n");
	printf("2.) Album\n");
	printf("3.) Song\n");
	printf("4.) Genre\n");
	printf("5.) Minutes\n");
	printf("6.) Seconds\n");
	printf("7.) Times Played\n");
	printf("8.) Rating\n");
	printf("9.) Done\n");
	printf(">>> ");
	
}

void sort(void) {

}

Node* findSongByArtist(List *playlist) {
	
	int numResults = 0;
	int choice = 0;
	char name[30];

	Node *songToEdit = NULL;

	printf("Please enter Artist's Name as (Last, First) or Only Name (ie RZA):\n");
	printf(">>> ");
	getchar();
	fgets(name, 30, stdin);
	strtok(name, "\n");

	
	numResults = printAllByArtist(playlist->head, name);
	if (numResults > 0) {
		printf("Please enter the ID of the song you'd like to edit:\n");
		printf(">>> ");
		scanf("%d", &choice);

		songToEdit = findByID(playlist, choice);
	}
	else {
		songToEdit = NULL;
		printMessage("Could not find any songs by that artist");
	}

	return songToEdit;
}

Node* findSongBySongName(List *playlist) {

	char song[30];

	Node *songToEdit = NULL;

	printf("Please enter song name:\n");
	printf(">>> ");
	getchar();
	fgets(song, 30, stdin);
	strtok(song, "\n");

	songToEdit = findBySongName(playlist, song);

	return songToEdit;
}

void rate(List *playlist) {
	Node *songToEdit = findSongByArtist(playlist);

	int choice = inputCheck(1, 5, printStarOptions);

	if (songToEdit != NULL) {
		songToEdit->record.rating = choice;
	}
}

void printStarOptions(void) {
	printf("1.) 1 Star\n");
	printf("2.) 2 Stars\n");
	printf("3.) 3 Stars\n");
	printf("4.) 4 Stars\n");
	printf("5.) 5 Stars\n");
	printf(">>> ");

}

void play(List *playlist) {
	
	Node *tempNode = NULL;

	int min = 0;
	int sec = 0;

	if (playlist->head != NULL) {

		tempNode = playlist->head;

		for (int i = 0; i < playlist->length; ++i) {
			system("cls");
			min = (1000 * 60 * tempNode->record.duration.min) * TIMESCALE;
			sec = (1000 * tempNode->record.duration.sec) * TIMESCALE;
			
			printf("Current Song:\n");
			printOneRecord(tempNode);


			if (tempNode->pNext != NULL) {
				tempNode = tempNode->pNext;
				printf("Up Next: \n");
				printOneRecord(tempNode);
				
				
			}
			printf("%d:%d: ", tempNode->record.duration.min, tempNode->record.duration.sec);
			loadingBar(min + sec);
			printf("--- 0:00\n");
			Sleep((min + sec) / 5);
		}
		system("pause");

	}
}

void loadingBar(int time) {
	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
	printf("---");

	Sleep(time / 10);
}

void shuffle(void) {

}

void exit(void) {

}

void test(void) {
	List playlist;
	initList(&playlist);

	//Record test1;
	//newRecord(&test1, "Black Keys", "Attack and Release", "All You Ever Wanted", "Blues", 2, 56, 200, 5);

	//Record test2;
	//newRecord(&test2, "Black Keys", "Attack and Release", "I Got Mine", "Blues", 3, 59, 500, 5);

	//Record test3;
	//newRecord(&test3, "Electric Six", "Fire", "Formula 409", "Rock", 3, 59, 700, 5);
	
	FILE *infile = fopen("test.csv", "r");

	load(&playlist, infile);

	display(&playlist);

	swap2Nodes(&playlist, playlist.head);

	printf("\n");

	display(&playlist);
	
	printf("\n");


	fclose(infile);
}