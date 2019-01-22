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

void NewFitbitData(FitbitData *f);

void parseLine(char *line);