#include "functions.h"

int main(int argc, char *argv[]) {
	
	FitbitData *myFBD_p;
	// NewFitbitData(myFBD_p);

	//FILE *infile = fopen("FitbitData.csv", "r");
	FILE *infile = fopen("test.csv", "r");
	
	// Checks if file exists
	if (infile != NULL) {
		
		char line[100];
		static int i = 0;
		char c = ' ';

		
		do {
			c = getc(infile);
			if (c != EOF) {
				line[0] = c;
				fgets(&line[1], 100, infile);
				printf("%d: %s", ++i, line);
			}

		} while (c != EOF);

	}



	return 0;
}