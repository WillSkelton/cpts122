#include "functions.h"

void NewFitbitData(FitbitData *f) {

	FitbitData FBD;
	for (int i = 0; i < PATIENTNAMELENGTH; ++i) FBD.patient[i] = '\0';
	for (int i = 0; i < PATIENTMINUTES; ++i) FBD.minute[i] = '\0';


	FBD.calories = 0.0;
	FBD.distance = 0.0;
	FBD.floors = 0;
	FBD.heartRate = 0;
	FBD.steps = 0;
	FBD.sleepLevel = 0;
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

void traverseFile(FILE *infile, FitbitData fbd[1440]) {

	// Checks if file exists
	if (infile != NULL) {

		char line[100];
		static int i = 0;
		char c = ' ';
		char *token;
		char patientName[6];
		char *x;


		c = getc(infile);
		if (c != EOF) {
			line[0] = c;
			fgets(&line[1], 100, infile);

			// Get Patient Name
			token = strtok(line, ",");
			token = strtok(NULL, ",");
			strcpy(patientName, token);
			fgets(line, 100, infile);

			do {
				
				c = getc(infile);
				if (c != EOF) {
					line[0] = c;
					fgets(&line[1], 100, infile);

					x = strtok(line, ",");
					++i;

					if (strcmp(x, patientName) == 0) {

						printf("%d: %s\n", i, line);
					}

				}

			} while (c != EOF);

		}
	}
}
