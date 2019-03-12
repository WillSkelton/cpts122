#include "DietPlan.h"
#include "ExercizePlan.h"

int main(void) {


	//time_t myTime = time(NULL);
	//string str = ctime(&myTime);
	//cout << str.substr(8,2) << endl;

	ExercizePlan myPlan("Stuff", 345);
	myPlan.setDate("3/11/2019");
	
	myPlan.setStepGoal(375);

	
	myPlan.setName("Horkey");

	cout << "Name: " << myPlan.getName() << " | Goal: " <<  myPlan.getStepGoal() << "\n";

	return 0;
}

