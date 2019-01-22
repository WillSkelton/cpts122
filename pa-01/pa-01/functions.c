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

void parseLine(char *str, char *line) {
	char *token;

	//token = strtok(line, ",");
	//printf("Token: %s\n", token);
	//while (token != NULL) {
	//	token = strtok(NULL, ",");
	//	printf("Token: `%s`\n", token);
	//}
	//fgets(line, 100, infile);
	
	token = strtok(line, ",");
	printf("Token: %s\n", token);
	while (token != NULL) {
		token = strtok(NULL, ",");
		printf("Token: `%s`\n", token);
	}
}

void traverseFile(FILE *infile) {

	// Checks if file exists
	if (infile != NULL) {

		FitbitData FBD[1440];
		char line[100];
		int i = 0;
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

						// Patient
						strncpy(lineData.patient, patientName, PATIENTNAMELENGTH);

						// minute
						token = strtok(NULL, ",");
						strncpy(lineData.minute, token, PATIENTMINUTES);

						// calories

						/*
						Okay Future Will, Here's how this works:
						1.) if cell is empty (,,),
							- (109) token looks like this ",calories...". Copy that into line w/o ','
							- (110) set token and line to the next entry thus skipping the ",,"
						2.) otherwise, if not empty,
							- (113) token looks like this ",calories...". Copy that into line
							- (114) remove calories from line
							- (115) put line into struct
						*/
						token = strtok(NULL, "");            // Check if empty
						if (token[0] == ',') {
							strcpy(line, &token[1]);         // copies everything after the comma into line
							token = strtok(line, ",");
						}
						else {
							strcpy(line, token);
							token = strtok(line, ",");
							sscanf(line, "%lf", &lineData.calories);
						}

						FBD[i] = lineData;

						NewFitbitData(&lineData);

						printf("%d: %s\n", i, FBD[i].patient);
						++i;
					}
					
				}

				

			} while (c != EOF);

		}
	}
}
