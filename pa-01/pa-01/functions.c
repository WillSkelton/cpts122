#include "functions.h"

void NewFitbitData(FitbitData *f) {

	// FitbitData FBD;
	for (int i = 0; i < PATIENTNAMELENGTH; ++i) f->patient[i] = '\0';
	for (int i = 0; i < PATIENTMINUTES; ++i) f->minute[i] = '\0';


	f->calories = 0.0;
	f->distance = 0.0;
	f->floors = 0;
	f->heartRate = 0;
	f->steps = 0;
	f->sleepLevel = 0;
}

void clearStats(Stats *s) {
	for (int i = 0; i < PATIENTNAMELENGTH; ++i) s->patientName[i] = '\0';
	s->totalCalories = 0.0;
	s->totalDistance = 0.0;
	s->floors = 0;
	s->totalSteps = 0;
	s->maxSteps = 0;
	s->poorestSleepStreak = 0;
	s->currentSleepStreak = 0;
	s->numLines = 0;
	s->avgHeart = 0;
}

unsigned int checkForMaxSteps(unsigned int maxSteps, unsigned int steps) {
	
	return ((steps >= maxSteps) ? steps : maxSteps);
}

unsigned int checkForBadSleep(unsigned int streak, unsigned int currentStreak) {

	return ((streak >= currentStreak) ? streak : currentStreak);
}

void parseLine(FitbitData *f, Stats *s, char* patientName) {
	char *token;
	char line[100];

	// Patient
	strncpy(&f->patient, patientName, PATIENTNAMELENGTH);

	// minute
	token = strtok(NULL, ",");
	strncpy(f->minute, token, PATIENTMINUTES);

	// calories
	token = strtok(NULL, "");            // Check if empty
	if (token[0] == ',') {
		strcpy(line, &token[1]);         // copies everything after the comma into line
		token = strtok(line, ",");
	}
	else {
		strcpy(line, token);
		token = strtok(line, ",");
		sscanf(line, "%lf", &f->calories);
		s->totalCalories += f->calories; // update total calories
	}

	// Distance
	token = strtok(NULL, "");
	if (token[0] == ',') {
		strcpy(line, &token[1]);         // copies everything after the comma into line
		token = strtok(line, ",");
	}
	else {
		strcpy(line, token);
		token = strtok(line, ",");
		sscanf(line, "%lf", &f->distance);
		s->totalDistance += f->distance;
	}

	// Floors
	token = strtok(NULL, "");
	if (token[0] == ',') {
		strcpy(line, &token[1]);         // copies everything after the comma into line
		token = strtok(line, ",");
	}
	else {
		strcpy(line, token);
		token = strtok(line, ",");
		sscanf(line, "%d", &f->floors);
		s->floors += f->floors;
	}

	// Heart
	token = strtok(NULL, "");
	if (token[0] == ',') {
		strcpy(line, &token[1]);         // copies everything after the comma into line
		token = strtok(line, ",");
	}
	else {
		strcpy(line, token);
		token = strtok(line, ",");
		sscanf(line, "%d", &f->heartRate);
		s->avgHeart += f->heartRate;
	}

	// Steps
	token = strtok(NULL, "");
	if (token[0] == ',') {
		strcpy(line, &token[1]);         // copies everything after the comma into line
		token = strtok(line, ",");
	}
	else {
		strcpy(line, token);
		token = strtok(line, ",");
		sscanf(line, "%d", &f->steps);
		s->totalSteps += f->steps;

		s->maxSteps = checkForMaxSteps(s->maxSteps, f->steps);
	}

	// Sleep Level
	token = strtok(NULL, "");
	if (token != NULL && token[0] == ',') {
		strcpy(line, &token[1]);         // copies everything after the comma into line
		token = strtok(line, ",");
	}
	else {
		if (token != NULL) {
			strcpy(line, token);
			token = strtok(line, ",");
			sscanf(line, "%d", &f->sleepLevel);

			if (f->sleepLevel > 1) {
				s->currentSleepStreak += f->sleepLevel;
			}
			else {
				s->poorestSleepStreak = checkForBadSleep(s->poorestSleepStreak, s->currentSleepStreak);
				s->currentSleepStreak = 0;			
			}
		}
	}
	s->numLines++;
}

void traverseFile(FILE *infile) {

	// Checks if file exists
	if (infile != NULL) {

		FitbitData FBD[1500];
		Stats stats;
		clearStats(&stats);
		char line[100], c = ' ', *token = NULL, patientName[6], *nameOnLine;
		static char lastLine[100];
		int i = 0, danger = 3;

		c = getc(infile);
		if (c != EOF) {
			line[0] = c;
			fgets(&line[1], 100, infile);

			// Get Patient Name
			token = strtok(line, ",");
			token = strtok(NULL, ",");
			strcpy(patientName, token);
			strcpy(stats.patientName, patientName);
			
			// Throws away header line
			fgets(line, 100, infile);

			do {
				
				// Checks for EOF
				c = getc(infile);

				if (c != EOF) { // not EOF
					
					// Puts first char back into line after getc
					line[0] = c;
					fgets(&line[1], 100, infile);

					if (strcmp(lastLine, line) == 0) {
						strcpy(lastLine, line);
						continue;
					}
					else {
						strcpy(lastLine, line);
						// printf("%d: %s", i, line);

					}

					//Gets the name on a certain line
					token = strtok(line, ",");
					
					nameOnLine = token;

					// If line belongs to patient, add stuff to struct
					if (strcmp(nameOnLine, patientName) == 0) {

						FitbitData lineData;
						NewFitbitData(&lineData);

						parseLine(&lineData, &stats, patientName);

						FBD[i] = lineData;

						NewFitbitData(&lineData);

						++i;
					}
				}
				
			} while (c != EOF);
			
			stats.avgHeart /= stats.numLines;	
		}
		
		printTheStuff(&FBD, &stats);
	}
}

int strlenrec(char *str) {
	static int n = 0;
	if (str[0] != '\0') {
		++n;
		strlenrec(&str[1]);
	}
	
	return n;
}

void printTheStuff(FitbitData FBD[1500], Stats *stats) {
	FILE *outfile = fopen("Results.csv", "w");
	
	int i = 0;
	double totalCalories = stats->totalCalories;
	double totalDistance = stats->totalDistance;
	unsigned int floors = stats->floors;
	unsigned int totalSteps = stats->totalSteps;
	unsigned int maxSteps = stats->maxSteps;
	unsigned int streak = stats->poorestSleepStreak;
	double avgHeart = stats->avgHeart;

	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile, "%lf,%lf,%d,%lf,%d,%d", totalCalories, totalDistance, totalSteps, avgHeart, maxSteps, streak);
	
	while (strcmp(FBD[i].patient, stats->patientName) == 0) {
		fprintf(outfile, "\n%s,%s,%lf,%lf,%d,%d,%d,%d", FBD[i].patient, FBD[i].minute, FBD[i].calories,
			FBD[i].distance, FBD[i].floors, FBD[i].heartRate, FBD[i].steps, FBD[i].sleepLevel);

		++i;
	}

	fclose(outfile);

}
