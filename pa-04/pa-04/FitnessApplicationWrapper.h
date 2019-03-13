#pragma once
#include "DietPlan.h"
#include "ExercizePlan.h"


class FitnessAppWrapper {
public:
	// CTOR
	FitnessAppWrapper();
	
	// DTOR
	~FitnessAppWrapper();

	// Utility
	void runApp(void);
	void loadDailyPlan(ifstream &ifileStream, DietPlan &plan);
	void loadWeeklyPlan(ifstream &ifileStream, vector<DietPlan *> &weeklyPlan);

	void loadDailyPlan(ifstream &ifileStream, ExercizePlan &plan);
	void loadWeeklyPlan(ifstream &ifileStream, vector<ExercizePlan *> &weeklyPlan);

	void displayMenu(void);

	void closeFiles(void);

	// GET
	void displayDailyPlan(void);
	void displayWeeklyPlan(void);

	// PUT
	void storeDailyPlan(void);
	void storeWeeklyPlan(void);
	
private:
	vector<ExercizePlan *> weeklyExercizePlan;
	vector<DietPlan *> weeklyDietPlan;

	ifstream exercizeFile;
	ifstream dietFile;
};

/*
# void runApp (void): starts the main application.

# void loadDailyPlan (fstream &fileStream, DietPlan &plan): must define two of these functions; one for a DietPlan and one for an ExercisePlan.
	This function reads one record from the given stream. 
	These will be considered overloaded functions! Precondition: file is already open!

# void loadWeeklyPlan (fstream &fileStream, DietPlan weeklyPlan[ ]): must define two of these functions; one for a DietPlan and one for an ExercisePlan.
	This function must read in all seven daily plans from the given stream. 
	Note: the array parameter would change if using a vector or linked list! 
	This function should call loadDailyPlan () directly. Precondition: file is already open!

# displayDailyPlan (): writes a daily plan to the screen. You must apply the overloaded stream insertion operator here! 
	Note: you must determine the appropriate parameters and return type. Once again you must define two of these!

# displayWeeklyPlan (): writes a weekly plan to the screen. 
	This function must call displayDailyPlan (). Note: you must determine the appropriate parameters and return type. 
	Once again you must define two of these!

# storeDailyPlan (): writes a daily plan to a file. You must apply the overloaded stream insertion operator here! 
	Note: you must determine the appropriate parameters and return type. Once again you must define two of these!

# storeWeeklyPlan (): writes a weekly plan to a file. This function must call storeDailyPlan (). 
	You must apply the overloaded stream insertion operator here! Note: you must determine the appropriate parameters and return type. 
	Once again you must define two of these!

# displayMenu (): displays nine menu options. These include:
	1. Load weekly diet plan from file.
	2. Load weekly exercise plan from file.
	3. Store weekly diet plan to file.
	4. Store weekly exercise plan to file.
	5. Display weekly diet plan to screen.
	6. Display weekly exercise plan to screen.
	7. Edit daily diet plan.
	8. Edit daily exercise plan.
	9. Exit.   // Note: this must write the most recent weekly plans to the corresponding files.
*/

// CTOR
FitnessAppWrapper::FitnessAppWrapper() {
	this->exercizeFile.open("exercizePlans.txt");
	this->dietFile.open("dietPlans.txt");

	cout << "there" << endl;
}


// DTOR
FitnessAppWrapper::~FitnessAppWrapper() {
	this->closeFiles();

}

// Utility
void FitnessAppWrapper::runApp(void) {
	DietPlan dietPlan;

	this->loadWeeklyPlan(this->dietFile, this->weeklyDietPlan);
}

void FitnessAppWrapper::loadDailyPlan(ifstream &fileStream, DietPlan &plan) {
	//ifstream infile;
	//infile.open("test.txt");
	string line;
	this->dietFile >> line;
	plan.setName(line);

	this->dietFile >> line;
	plan.setCalorieGoal(stoi(line));

	this->dietFile >> line;
	plan.setDate(line);

	cout << "Name: " << plan.getName() << endl;
	cout << "Goal: " << plan.getCalorieGoal() << endl;
	cout << "Date: " << plan.getDate() << endl;

}

void FitnessAppWrapper::loadWeeklyPlan(ifstream &fileStream, vector<DietPlan *> &weeklyPlan) {
	int i = 0;
	while (fileStream.eof() != 1) {
		DietPlan *dailyPlan = new DietPlan;
		this->loadDailyPlan(this->dietFile, *(dailyPlan));

		this->weeklyDietPlan.push_back(dailyPlan);


		i++;
		cout << "i: " << i << endl;
	}

	for (int i = 0; i < 7; ++i) {
		cout << this->weeklyDietPlan[i]->getName() << "-->";
	}
	cout << endl;
}

void FitnessAppWrapper::loadDailyPlan(ifstream &fileStream, ExercizePlan &plan) {

}

void FitnessAppWrapper::loadWeeklyPlan(ifstream &fileStream, vector<ExercizePlan *> &weeklyPlan) {

}

void FitnessAppWrapper::displayMenu(void) {

}

void FitnessAppWrapper::closeFiles(void) {
	this->exercizeFile.close();
	this->dietFile.close();
}

// GET
void FitnessAppWrapper::displayDailyPlan(void) {

}

void FitnessAppWrapper::displayWeeklyPlan(void) {

}

// PUT
void FitnessAppWrapper::storeDailyPlan(void) {

}

void FitnessAppWrapper::storeWeeklyPlan(void) {

}

