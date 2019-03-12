#include "FitnessApplicationWrapper.h"

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//using std::cout;
//using std::string;
//using std::endl;
//using std::array;
//using std::vector;
//using std::fstream;

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

