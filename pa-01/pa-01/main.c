#include "functions.h"

int main(int argc, char *argv[]) {
	
	
	// NewFitbitData(myFBD_p);

	//FILE *infile = fopen("FitbitData.csv", "r");
	FILE *infile = fopen("test.csv", "r");

	traverseFile(infile);

	fclose(infile);
	return 0;
}