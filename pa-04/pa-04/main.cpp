#include "FitnessApplicationWrapper.h"

int main(void) {

	//time_t myTime = time(NULL);
	//string str = ctime(&myTime);
	//cout << str.substr(8,2) << endl;

	//fstream infile("test.txt");
	//// infile.open("test.txt");
	//string line;

	FitnessAppWrapper app;
	
	app.runApp();

	return 0;
}

