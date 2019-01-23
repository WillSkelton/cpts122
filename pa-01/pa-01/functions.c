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

void parseLine(FitbitData *f, char* patientName) {
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
		}

	}
}

void traverseFile(FILE *infile) {

	// Checks if file exists
	if (infile != NULL) {

		FitbitData FBD[1500];
		char line[100];
		int i = 0;
		int danger = 3;
		char c = ' ';
		char *token;
		char patientName[6];
		char *nameOnLine;



		c = getc(infile);
		if (c != EOF) {
			line[0] = c;
			fgets(&line[1], 100, infile);

			// Get Patient Name
			token = strtok(line, ",");
			token = strtok(NULL, ",");
			strcpy(patientName, token);
			
			// Throws away header line
			fgets(line, 100, infile);

			do {
				
				// Checks for EOF
				c = getc(infile);

				if (c != EOF) { // not EOF
					
					// Puts first char back into line after getc
					line[0] = c;
					fgets(&line[1], 100, infile);

					//Gets the name on a certain line
					token = strtok(line, ",");
					nameOnLine = token;

					// If line belongs to patient, add stuff to struct
					if (strcmp(nameOnLine, patientName) == 0) {

						

						FitbitData lineData;
						NewFitbitData(&lineData);

						parseLine(&lineData, patientName);
						
						if (i == 379) {
							printf("\n");
						}

						FBD[i] = lineData;

						NewFitbitData(&lineData);

						//printf("%d: %lf\n", i+1, FBD[i].calories);
						++i;

						
					}
					danger++;
					printf("%d\n", danger);
				}		
			} while (c != EOF);
			printf("done\n");
		}
	}
}
