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
	void loadDailyPlan(fstream &ifileStream, DietPlan &plan);
	void loadWeeklyPlan(fstream &ifileStream, vector<DietPlan *> &weeklyPlan);

	void loadDailyPlan(fstream &ifileStream, ExercizePlan &plan);
	void loadWeeklyPlan(fstream &ifileStream, vector<ExercizePlan *> &weeklyPlan);

	int displayMenu(void);

	void closeFiles(void);
	void openFilesForReading(void);
	void openFilesForWriting(void);


	// GET
	void displayDailyDietPlan(DietPlan &plan);
	void displayWeeklyDietPlan(void);

	void displayDailyExercizePlan(ExercizePlan &plan);
	void displayWeeklyExercizePlan(void);

	// PUT
	void FitnessAppWrapper::storeDailyDietPlan(DietPlan &plan);

	void FitnessAppWrapper::storeWeeklyDietPlan(void);

	void FitnessAppWrapper::storeDailyExercizePlan(ExercizePlan &plan);

	void FitnessAppWrapper::storeWeeklyExercizePlan(void);

	// Operators
	friend ostream & operator << (ostream &lhs, DietPlan &rhs);
	friend ostream & operator << (ostream &lhs, ExercizePlan &rhs);

	friend istream & operator >> (istream &lhs, DietPlan &rhs);
	friend istream & operator >> (istream &lhs, ExercizePlan &rhs);
	
private:
	vector<ExercizePlan *> weeklyExercizePlan;
	vector<DietPlan *> weeklyDietPlan;

	fstream exercizeFile;
	fstream dietFile;
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
	this->openFilesForReading();
}

// DTOR
FitnessAppWrapper::~FitnessAppWrapper() {
	
	int weeklyDietPlanSize = this->weeklyDietPlan.size();
	int weeklyExercizePlanSize = this->weeklyExercizePlan.size();

	for (int i = 0; i < weeklyDietPlanSize; i++) {
		delete this->weeklyDietPlan[i];
	}

	for (int i = 0; i < weeklyExercizePlanSize; i++) {
		delete this->weeklyExercizePlan[i];
	}

	this->closeFiles();

}

// Utility
void FitnessAppWrapper::runApp(void) {
	int choice = 0;
	do {
		choice = this->displayMenu();
		switch (choice) {
		case 1:
			this->loadWeeklyPlan(this->dietFile, this->weeklyDietPlan);
			break;

		case 2:
			this->loadWeeklyPlan(this->exercizeFile, this->weeklyExercizePlan);
			break;

		case 3:
			this->storeWeeklyDietPlan();
			break;

		case 4:
			this->storeWeeklyExercizePlan();
			break;

		case 5:
			this->displayWeeklyDietPlan();
			system("pause");
			break;

		case 6:
			this->displayWeeklyExercizePlan();
			system("pause");
			break;

		case 7:
			// Edit Diet Plan
			break;

		case 8:
			// Edit exercize plan
			break;

		case 9:
			//Exit
			break;

		default:
			cout << "I'm not sure how you got here" << endl;
			break;

		}


	} while (choice != 9);
	/*this->loadWeeklyPlan(this->dietFile, this->weeklyDietPlan);
	
	this->loadWeeklyPlan(this->exercizeFile, this->weeklyExercizePlan);

	this->displayWeeklyDietPlan();

	this->displayWeeklyExercizePlan();

	this->storeWeeklyDietPlan();

	this->storeWeeklyExercizePlan();*/

	this->closeFiles();

	//this->~FitnessAppWrapper();
}

// GET
//// Load Daily Diet Plan
void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan) {
	fileStream >> plan;
}

//// Load Weekly Diet Plan
void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, vector<DietPlan *> &weeklyPlan) {

	this->openFilesForReading();

	while (fileStream.eof() != 1) {
		
		DietPlan *dailyPlan = new DietPlan;
		
		this->loadDailyPlan(this->dietFile, *(dailyPlan));

		this->weeklyDietPlan.push_back(dailyPlan);

	}
	
	this->closeFiles();

}

//// Load Daily Exercize Plan
void FitnessAppWrapper::loadDailyPlan(fstream &fileStream,  ExercizePlan &plan) {
	fileStream >> plan;

}

//// Load Weekly Exercize Plan 
void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, vector<ExercizePlan *> &weeklyPlan) {

	this->openFilesForReading();
	while (fileStream.eof() != 1) {
		
		ExercizePlan *dailyPlan = new ExercizePlan;
		
		this->loadDailyPlan(this->exercizeFile, *(dailyPlan));

		this->weeklyExercizePlan.push_back(dailyPlan);

	}

	this->closeFiles();
}


int FitnessAppWrapper::displayMenu(void) {
	int choice = 0;

	do {
		system("cls");
		cout << "1.) Load weekly diet plan from file." << endl
			<< "2.) Load weekly exercise plan from file." << endl
			<< "3.) Store weekly diet plan to file." << endl
			<< "4.) Store weekly exercise plan to file." << endl
			<< "5.) Display weekly diet plan to screen." << endl
			<< "6.) Display weekly exercise plan to screen." << endl
			<< "7.) Edit daily diet plan." << endl
			<< "8.) Edit daily exercise plan." << endl
			<< "9.) Exit. // Note: this must write the most recent weekly plans to the corresponding files." << endl
			<< ">>> ";
		cin >> choice;

	} while (choice < 1 || choice > 9);


	
	cout << choice << endl; 

	return choice;
}

void FitnessAppWrapper::openFilesForReading(void){
	if (this->exercizeFile.is_open() == false) {
		this->exercizeFile.open("exercizePlans.txt", ios::in);
	}
	else {
		this->exercizeFile.close();
		this->exercizeFile.open("exercizePlans.txt", ios::in);
	}

	if (this->dietFile.is_open() == false) {
		this->dietFile.open("dietPlans.txt", ios::in);
	}
	else {
		this->dietFile.close();
		this->dietFile.open("dietPlans.txt", ios::in);

	}
}

void FitnessAppWrapper::openFilesForWriting(void) {
	if (this->exercizeFile.is_open() == false) {
		this->exercizeFile.open("exercize-test.txt", ios::out);
	}
	else {
		this->exercizeFile.close();
		this->exercizeFile.open("exercize-test.txt", ios::out);
	}

	if (this->dietFile.is_open() == false) {
		this->dietFile.open("diet-test.txt", ios::out);
	}
	else {
		this->dietFile.close();
		this->dietFile.open("diet-test.txt", ios::out);
	}
}

void FitnessAppWrapper::closeFiles(void) {
	this->exercizeFile.close();
	this->dietFile.close();
}


void FitnessAppWrapper::displayDailyDietPlan(DietPlan &plan) {
	cout << "Name: " << plan.getName() << endl
		<< "Goal: " << plan.getCalorieGoal() << " Max Calories" << endl
		<< "Date: " << plan.getDate() << endl;
}

void FitnessAppWrapper::displayWeeklyDietPlan(void) {
	cout << "===== Weekly Diet Plan: =====" << endl;
	int weeklyDietPlanSize = this->weeklyDietPlan.size();

	for (int i = 0; i < weeklyDietPlanSize; i++) {
		cout << "----- Day: " << i + 1 << " -----" << endl;
		displayDailyDietPlan(*(this->weeklyDietPlan[i]));
		cout << "------------------" << endl << endl;
	}
	cout << "=============================" << endl;

}

void FitnessAppWrapper::displayDailyExercizePlan(ExercizePlan &plan) {
	cout << "Name: " << plan.getName() << endl
		<< "Goal: " << plan.getStepGoal() << " Steps" << endl
		<< "Date: " << plan.getDate() << endl;

}

void FitnessAppWrapper::displayWeeklyExercizePlan(void) {
	int weeklyExercizePlanSize = this->weeklyExercizePlan.size();

	cout << "=== Weekly Exercize Plan: ===" << endl;

	for (int i = 0; i < weeklyExercizePlanSize; i++) {
		cout << "----- Day: " << i + 1 << " -----" << endl;
		displayDailyExercizePlan(*(this->weeklyExercizePlan[i]));
		cout << "------------------" << endl << endl;
	}
	cout << "=============================" << endl;

}

// PUT
void FitnessAppWrapper::storeDailyDietPlan(DietPlan &plan) {
	
	/*this->dietFile << plan.getName() << endl
		<< to_string(plan.getCalorieGoal()) << endl
		<< plan.getDate() << endl
		<< endl;*/
	this->dietFile << plan;
}

void FitnessAppWrapper::storeWeeklyDietPlan(void) {

	this->openFilesForWriting();

	int weeklyDietPlanSize = this->weeklyDietPlan.size();

	for (int i = 0; i < weeklyDietPlanSize; i++) {
		this->storeDailyDietPlan(*(this->weeklyDietPlan[i]));
		
		if (i < weeklyDietPlanSize - 1) {
			this->dietFile << endl << endl;
		}
	}


	this->closeFiles();


}

void FitnessAppWrapper::storeDailyExercizePlan(ExercizePlan &plan) {
	this->exercizeFile << plan;

}

void FitnessAppWrapper::storeWeeklyExercizePlan(void) {
	
	this->openFilesForWriting();

	int weeklyExercizePlanSize = this->weeklyExercizePlan.size();

	for (int i = 0; i < weeklyExercizePlanSize; i++) {
		this->storeDailyExercizePlan(*(weeklyExercizePlan[i]));
		
		if (i < weeklyExercizePlanSize - 1) {
			this->exercizeFile << endl << endl;
		}
	}


	this->closeFiles();
}


// Non-Member
// Operators
//	- Insertion
ostream & operator << (ostream &lhs, DietPlan &rhs) {
	
	lhs << rhs.getName() << endl
		<< to_string(rhs.getCalorieGoal()) << endl
		<< rhs.getDate();// << endl;
		//<< endl;

	return lhs;
}

ostream & operator << (ostream &lhs, ExercizePlan &rhs) {
	lhs << rhs.getName() << endl
		<< to_string(rhs.getStepGoal()) << endl
		<< rhs.getDate();// << endl;
		//<< endl;

	return lhs;
}

//	- Extraction
istream & operator >> (istream &lhs, DietPlan &rhs) {
	string line;
	
	lhs >> line;
	rhs.setName(line);

	lhs >> line;
	rhs.setCalorieGoal(stoi(line));

	lhs >> line;
	rhs.setDate(line);

	return lhs;
}

istream & operator >> (istream &lhs, ExercizePlan &rhs) {
	string line;

	lhs >> line;
	rhs.setName(line);

	lhs >> line;
	rhs.setStepGoal(stoi(line));

	lhs >> line;
	rhs.setDate(line);

	return lhs;
}