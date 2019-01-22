#include "functions.h"

int main(int argc, char *argv[]) {
	
	FitbitData myFBD[1440];
	// NewFitbitData(myFBD_p);

	//FILE *infile = fopen("FitbitData.csv", "r");
	FILE *infile = fopen("test.csv", "r");

	traverseFile(infile, myFBD);


	fclose(infile);
	return 0;
}