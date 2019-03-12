#include "DietPlan.h"

int main(void) {


	//time_t myTime = time(NULL);
	//string str = ctime(&myTime);
	//cout << str.substr(8,2) << endl;

	DietPlan myPlan("Stuff", 345);
	myPlan.setDate("3/11/2019");
	
	cout << myPlan.getDate() << "\n";

	return 0;
}

