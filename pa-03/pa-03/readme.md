# Programming Assignment 3:

## functions.h:

#### menuREPL
- Description: Main menu for the program.
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void menuREPL(void);
```

#### printBorder
- Description: prints a desired length of = or - depending on input
- Input Parameters: size: (- or =), length: (number of = or -)
- Returns: n/a
- Declaration:
```c
void printBorder(int size, int length);
```

#### inputCheck
- Description: prints a menu and then gets user input between upper and lower bounds.
- Input Parameters: lower and upper bounds of acceptable input, menu to print
- Returns: the user's choice
- Declaration:
```c
int inputCheck(int lowerBound, int upperBound, void(*printMenu)());
```

#### printMessage
- Description: print a message surrounded by = and ||
- Input Parameters: char* message
- Returns: n/a
- Declaration:
```c
void printMessage(char *message);
```

#### printMenu
- Description: prints main menu
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void printMenu(void);
```

#### load
- Description: traverses file and loads contents into a linked list
- Input Parameters: pointer to linked list
- Returns: n/a
- Declaration:
```c
void load(List *listplaylist, FILE *infile);
```

#### parseLine
- Description: reads a line from a file and creates a node for a linked list based on that information
- Input Parameters: placeholder node and char array for information
- Returns: n/a
- Declaration:
```c
void parseLine(Node *tempRecord, char line[100]);
```

#### store
- Description: traverses linked list and writes all information to the file
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void store(List *playlist);
```

#### display
- Description: displays either all records or all records by a certain artist specified by the user
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void display(List *playlist);
```

#### printDisplayOptions
- Description: prints options to either display ALL records or all of a specific artist's records
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void printDisplayOptions(void);
```

#### insert
- Description: inserts a record at the beginning of the playlist
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void insert(List *playlist);
```

#### del
- Description: deletes a certain record
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void del(List *playlist);
```

#### findSongBySongName
- Description: gets a song name from the user and tries to find it
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
Node* findSongBySongName(List *playlist);
```

#### edit
- Description: finds a song, and lets the user go through and edit any of the properties before saving it.
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void edit(List *playlist);
```

#### printAttributes
- Description: prints all the attributes that are available for editing
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void printAttributes(void);
```

#### sort
- Description: uses bubble sort to sort the playlist based on a few categories
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void sort(List *playlist);
```

#### printSortOptions
- Description: prints the categories that the user can sort the playlist by
- Input n/a
- Returns: n/a
- Declaration:
```c
void printSortOptions(void);
```

#### findSongByArtist
- Description: asks the user for an artist name and finds all the songs by that artist
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
Node* findSongByArtist(List *playlist);
```

#### rate
- Description: allows the user to pick a song and change it's rating
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void rate(List *playlist);
```

#### printStarOptions
- Description: prints list of ratings the user can pick
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void printStarOptions(void);
```

#### play
- Description: traverses the playlist and 'plays' them at 10x speed for time's sake
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void play(List *playlist);
```

#### shufflePlay
- Description: randomly picks a song and goes in a random direction for a random number of songs to find the next song switching directions at the head and tail of the list.
- Input Parameters: pointer to the playlist
- Returns: an integer that represents the number of times the playlist was out of order. This is only used for testing.
- Declaration:
```c
int shufflePlay(List *playlist);
```

#### loadingBar
- Description: prints a simulated loading bar for the song
- Input Parameters: an integer representing the length of the son in seconds
- Returns: n/a
- Declaration:
```c
void loadingBar(int time);
```

#### exit
- Description: prints "Goodbye!"
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void exit(void);
```

#### runTests
- Description: run all the test functions
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void runTests(void);
```

#### testInsert
- Description: tests the insert function
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void testInsert(void);
```

#### testDelete
- Description: tests the del function
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void testDelete(void);
```

#### testSuffle
- Description: tests the shuffle function`
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void testSuffle(void);
```
