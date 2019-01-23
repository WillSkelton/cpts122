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
	double totalCalories;
	double totalDistance;
	unsigned int floors;
	unsigned int totalSteps;
	unsigned int maxSteps;
	unsigned int poorestSleepStreak;
	unsigned int numLines;
	double avgHeart;
} Stats;



void NewFitbitData(FitbitData *f);

void clearStats(Stats *s);

void parseLine(FitbitData *f, Stats *s, char* patientName);

void traverseFile(FILE *infile);

unsigned int checkForMaxSteps(unsigned int maxSteps, unsigned int steps);