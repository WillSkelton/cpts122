#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATIENTNAMELENGTH 10
#define PATIENTMINUTES 9



typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

typedef struct stats {
	char patientName[10];
	double totalCalories;
	double totalDistance;
	unsigned int floors;
	unsigned int totalSteps;
	unsigned int maxSteps;
	unsigned int currentSleepStreak;
	unsigned int poorestSleepStreak;
	unsigned int numLines;
	double avgHeart;
} Stats;


/*
# Description
- The function `void NewFitbitData(FitbitData *f)` goes through all the properties on a FitbitData struct and sets all the **integer** values to `0`, **double values** to `0.0`, and **strings** to `"\0\0\0\0\0\0\0..."` thus creating a "fresh" struct.

# Parameters
- *f: A pointer to the FitbitData struct that needs to be initialized or reset.

# Return Value
- This function doesn't return anything.
*/
void NewFitbitData(FitbitData *f);

/*
# Description
- The function `void clearStats(Stats *s)` goes through all the properties on a stats struct and sets all the **integer** values to `0`, **double values** to `0.0`, and **strings** to `"\0\0\0\0\0\0\0..."` thus creating a "fresh" struct.
# Parameters
- *s: A pointer to the stats struct that needs to be initialized or reset.
# Return Value
- This function doesn't return anything.
*/
void clearStats(Stats *s);

/*
# Description
- The function `void parseLine(FitbitData *f, Stats *s, char* patientName)` uses `strtok()` 
	from string.h to parse a line that looks like : `12cx7,0:04 : 00, 0.968900, 0.000000, 0, 70, 0, 1` 
	and stores the values in the respective properties on the FitbitData struct pointed to by `f`. Along the way, it updates the properties of the Stats struct pointed to by `s`.

# Preconditions
- This function can only called once the first two lines of the fitbit file have been removed from the buffer and the patient name has been stored in the stats struct pointed to by `s`.

# Parameters
- FitbitData *f: pointer to a FitbitData struct
- Stats *s : pointer to a Stats struct
- char *patientName : string containing the name of the owner of the file

# Return Value
- This function doesn't return anything.
*/
void parseLine(FitbitData *f, Stats *s, char* patientName);

/*
# Description
- This function iterates through the lines of a file and does 4 things:
	1. Gets the patient name from the file
	2. Passes each following line off to `void parseLine(FitbitData *f, Stats *s, char* patientName)` to be stored in a FitbitData struct
	3. Saves the struct to an array for later use
	4. Calls `void printTheStuff(FitbitData FBD[1500], Stats *stats)`
# Parameters
- FILE *infile: pointer to a file that's been opened to read
# Return Value
- This function doesn't return anything.
*/
void traverseFile(FILE *infile);

/*
# Description
- This function checks to see if the step count on the current line is the largest in the file.

# Parameters
- unsigned int maxSteps: Largest step count
- unsigned int steps: current step count

# Return Value
- the larger of the two arguments

*/
unsigned int checkForMaxSteps(unsigned int maxSteps, unsigned int steps);

/*
# Description
- This function checks to see if the current bad sleep streak is the largest in the file.
# Parameters
- unsigned int streak: Largest bad sleep streak
- unsigned int currentStreak: current bad sleep streak
# Return Value
- the larger of the two arguments
*/
unsigned int checkForBadSleep(unsigned int streak, unsigned int currentStreak);

/*
# Description
- This function prints all the stats (max steps, total calories, etc) to a file called `Results.csv`. Then, it loops through the array of FitbitData structs and prints the cleaned up data to the file as well.
# Parameters
- An array of FitbitData Structs of length 1500
- A pointer to the stats struct that contains all of the stats
# Return Value
- This function doesn't return anything.
*/
void printTheStuff(FitbitData FBD[1500], Stats *stats);

int strlenrec(char *str);