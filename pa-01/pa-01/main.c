#include "functions.h"

int main(int argc, char *argv[]) {
	
	FitbitData *myFBD_p;
	// NewFitbitData(myFBD_p);

	FILE *infile = fopen("FitbitData.csv", "r");
	
	// Checks if file exists
	if (infile != NULL) {
		char line[100];
		char *token;
		fgets(line, 100, infile);

		token = strtok(line, ",");
		printf("Token: %s\n", token);
	
		while (token != NULL) {
			token = strtok(NULL, ",");
			printf("Token: `%s`\n", token);
		}

		fgets(line, 100, infile);
		token = strtok(line, ",");
		printf("Token: %s\n", token);
		while (token != NULL) {
			token = strtok(NULL, ",");
			printf("Token: `%s`\n", token);
		}

		/*for (int i = 0; i < 3; ++i) {
			token = strtok(NULL, ",");
			printf("Token: `%s`\n", token);

			if (strcmp(token, "") != 0) {
				printf("Y'all different\n");
			}
		}*/
		
	}



	return 0;
}