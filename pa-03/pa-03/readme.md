# Programming Assignment 3:

## Table of Contents
[[toc]]

## functions:

### menuREPL
- Description: Main menu for the program.
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void menuREPL(void);
```

### printBorder
- Description: prints a desired length of = or - depending on input
- Input Parameters: size: (- or =), length: (number of = or -)
- Returns: n/a
- Declaration:
```c
void printBorder(int size, int length);
```

### inputCheck
- Description: prints a menu and then gets user input between upper and lower bounds.
- Input Parameters: lower and upper bounds of acceptable input, menu to print
- Returns: the user's choice
- Declaration:
```c
int inputCheck(int lowerBound, int upperBound, void(*printMenu)());
```

### printMessage
- Description: print a message surrounded by = and ||
- Input Parameters: char* message
- Returns: n/a
- Declaration:
```c
void printMessage(char *message);
```

### printMenu
- Description: prints main menu
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void printMenu(void);
```

### load
- Description: traverses file and loads contents into a linked list
- Input Parameters: pointer to linked list
- Returns: n/a
- Declaration:
```c
void load(List *listplaylist, FILE *infile);
```

### parseLine
- Description: reads a line from a file and creates a node for a linked list based on that information
- Input Parameters: placeholder node and char array for information
- Returns: n/a
- Declaration:
```c
void parseLine(Node *tempRecord, char line[100]);
```

### store
- Description: traverses linked list and writes all information to the file
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void store(List *playlist);
```

### display
- Description: displays either all records or all records by a certain artist specified by the user
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void display(List *playlist);
```

### printDisplayOptions
- Description: prints options to either display ALL records or all of a specific artist's records
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void printDisplayOptions(void);
```

### insert
- Description: inserts a record at the beginning of the playlist
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void insert(List *playlist);
```

### del
- Description: deletes a certain record
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void del(List *playlist);
```

### findSongBySongName
- Description: gets a song name from the user and tries to find it
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
Node* findSongBySongName(List *playlist);
```

### edit
- Description: finds a song, and lets the user go through and edit any of the properties before saving it.
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void edit(List *playlist);
```

### printAttributes
- Description: prints all the attributes that are available for editing
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void printAttributes(void);
```

### sort
- Description: uses bubble sort to sort the playlist based on a few categories
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void sort(List *playlist);
```

### printSortOptions
- Description: prints the categories that the user can sort the playlist by
- Input n/a
- Returns: n/a
- Declaration:
```c
void printSortOptions(void);
```

### findSongByArtist
- Description: asks the user for an artist name and finds all the songs by that artist
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
Node* findSongByArtist(List *playlist);
```

### rate
- Description: allows the user to pick a song and change it's rating
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void rate(List *playlist);
```

### printStarOptions
- Description: prints list of ratings the user can pick
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void printStarOptions(void);
```

### play
- Description: traverses the playlist and 'plays' them at 10x speed for time's sake
- Input Parameters: pointer to the playlist
- Returns: n/a
- Declaration:
```c
void play(List *playlist);
```

### shufflePlay
- Description: randomly picks a song and goes in a random direction for a random number of songs to find the next song switching directions at the head and tail of the list.
- Input Parameters: pointer to the playlist
- Returns: an integer that represents the number of times the playlist was out of order. This is only used for testing.
- Declaration:
```c
int shufflePlay(List *playlist);
```

### loadingBar
- Description: prints a simulated loading bar for the song
- Input Parameters: an integer representing the length of the son in seconds
- Returns: n/a
- Declaration:
```c
void loadingBar(int time);
```

### exit
- Description: prints "Goodbye!"
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void exit(void);
```

### runTests
- Description: run all the test functions
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void runTests(void);
```

### testInsert
- Description: tests the insert function
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void testInsert(void);
```

### testDelete
- Description: tests the del function
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void testDelete(void);
```

### testSuffle
- Description: tests the shuffle function`
- Input Parameters: n/a
- Returns: n/a
- Declaration:
```c
void testSuffle(void);
```

## Linked-List

### Rating Enum:
```c
typedef enum rating {
	NONE = 0, ONESTAR = 1, TWOSTAR = 2, THREESTAR = 3, FOURSTAR = 4, FIVESTAR = 5
} Rating;
```

### Duration Struct
```c
typedef struct duration {
	int min;
	int sec;
} Duration;
```

### Record Struct
```c
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
```

### Node Struct
```c
typedef struct node {
	Record record;
	struct node *pNext;
	struct node *pPrev;

} Node;
```


### linked list struct
```c
typedef struct list {
	Node *head;
	Node *tail;

	int length;


} List;
```


### initList
- Description:  Initialize list
- Input Parameters: a pointer to a list struct
- Returns: n/a
- Declaration:
```c
void initList(List *l);
```

### newRecord
- Description: Creates a new record
- Input Parameters: a pointer to a record struct and all of the necessary information for a record
- Returns: n/a
- Declaration:
```c
void newRecord(
  Record *r,
  char artist[30], 
  char album[30], 
  char song[30], 
  char genre[15], 
  int minutes, 
  int second, 
  int timesPlayed, 
  Rating rating
);
```

### newNode
- Description: makes a new node containing a record
- Input Parameters: a record struct
- Returns: pointer to the new node
- Declaration:
```c
Node* newNode(Record newRecord);
```
### printListL2R
- Description: recursively prints the list from left to right (Head to tail)
- Input Parameters: pointer to the head of the list (or wherever you want to start printing)
- Returns: n/a
- Declaration:
```c
void printListL2R(Node *nodePtr);
```
### printListR2L
- Description: recursively prints the list from right to left (tail to Head)
- Input Parameters: a pointer to the left most nod you want to start at
- Returns: n/a
- Declaration:
```c
void printListR2L(Node *nodePtr);
```
### printListTop2Bottom
- Description: same as printListL2R but formatted differently 
- Input Parameters: pointer to head node
- Returns:n/a
- Declaration:
```c
void printListTop2Bottom(Node *nodePtr);
```
### printAllByArtist
- Description: prints all the records by a certain artist
- Input Parameters: pointer to head node and a char* containing the artist name
- Returns: the number of songs by that artist
- Declaration:
```c
int printAllByArtist(Node *nodePtr, char *artist);
```
### printOneRecord
- Description: print a given record in the same format as `printListTop2Bottom`
- Input Parameters: pointer to a node
- Returns: n/a
- Declaration:
```c
void printOneRecord(Node *nodePtr);
```
### prepend
- Description:  adds a record to the head of the list
- Input Parameters: pointers to list and record
- Returns: 1 for success, 0 for fail
- Declaration:
```c
int prepend(List *list, Record *newRecord);
```
### append
- Description:  adds a record to the tail of the list
- Input Parameters: pointers to list and record
- Returns: 1 for success, 0 for fail
- Declaration:
```c
int append(List *list, Record *newRecord);
```
### deleteAllByArtist
- Description: traverses the list and deletes all songs by a certain artist
- Input Parameters: pointer to list and a char* wit the artist name
- Returns: 1 for success, 0 for fail
- Declaration:
```c
int deleteAllByArtist(List *list, char *artistName);
```
### findByID
- Description: finds a record with it's id
- Input Parameters: list pointer and id
- Returns: pointer to the record or NULL if not found
- Declaration:
```c
Node * findByID(List *list, unsigned long id);
```
### findBySongName
- Description: finds a song by song name
- Input Parameters: list pointer and char* with song name to find
- Returns: pointer to node or NUll if not found
- Declaration:
```c
Node* findBySongName(List *list, char *searchName);
```
### deleteSong
- Description: deletes a song
- Input Parameters: list pointer and pointer to the record to delete
- Returns: success
- Declaration:
```c
int deleteSong(List *list, Record *record);
```
### pop
- Description: removes the head of the list and shifts the head over one index
- Input Parameters: list pointer
- Returns: success
- Declaration:
```c
int pop(List *list);
```
### getLength
- Description: returns the length of the list. NOTE: Not used
- Input Parameters: list pointer, start index
- Returns: number of items in the list/sub-list
- Declaration:
```c
int getLength(Node *listPtr, int startIdx);
```
### getElementAtIndex
- Description: returns the element at a given index
- Input Parameters: list pointer and an index
- Returns: poiter to a node
- Declaration:
```c
Node* getElementAtIndex(List *list, int searchIdx);
```

### bubbleSortArtist
- Description: bubble sorts based on artist
- Input Parameters:list pointer
- Returns: n/a
- Declaration:
```c
void bubbleSortArtist(List *list);
```
### checkIfArtistSorted
- Description: checks if the list is sorted based on artist 
- Input Parameters: list pointer
- Returns: 1 if list is sorted 0 if not
- Declaration:
```c
int checkIfArtistSorted(List *list);
```
### bubbleSortSong
- Description: bubble sorts based on song name
- Input Parameters:list pointer
- Returns: n/a
- Declaration:
```c
void bubbleSortSong(List *list);
```
### checkIfSongSorted
- Description: checks if the list is sorted based on song name
- Input Parameters: list pointer
- Returns: 1 if list is sorted 0 if not
- Declaration:
```c
int checkIfSongSorted(List *list);
```
### bubbleSortAlbum
- Description: bubble sorts based on album name
- Input Parameters:list pointer
- Returns: n/a
- Declaration:
```c
void bubbleSortAlbum(List *list);
```
### checkIfAlbumSorted
- Description: checks if the list is sorted based on album name
- Input Parameters: list pointer
- Returns: 1 if list is sorted 0 if not
- Declaration:
```c
int checkIfAlbumSorted(List *list);
```
### bubbleSortTimesPlayed
- Description: bubble sorts based on times played
- Input Parameters:list pointer
- Returns: n/a
- Declaration:
```c
void bubbleSortTimesPlayed(List *list);
```
### checkIfTimesPlayedSorted
- Description: checks if the list is sorted based on times played
- Input Parameters: list pointer
- Returns: 1 if list is sorted 0 if not
- Declaration:
```c
int checkIfTimesPlayedSorted(List *list);
```
### bubbleSortRating
- Description: bubble sorts based on rating
- Input Parameters:list pointer
- Returns: n/a
- Declaration:
```c
void bubbleSortRating(List *list);
```
### checkIfRatingSorted
- Description: checks if the list is sorted based on rating
- Input Parameters: list pointer
- Returns: 1 if list is sorted 0 if not
- Declaration:
```c
int checkIfRatingSorted(List *list);
```
### swap2Nodes
- Description: swaps any node with the any other node
- Input Parameters: list pointer and pointers to the 2 nodes to swap
- Returns: n/a
- Declaration:
```c
void swap2Nodes(List *list, Node *a, Node *b);
```
### swap2NodesSimple
- Description: swaps any node with the one in front of it 
- Input Parameters: list pointer and pointer to node
- Returns: n/a
- Declaration:
```c
void swap2NodesSimple(List *list, Node *a);
```