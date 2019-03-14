#pragma once
#include "plan.h"

class DietPlan : public Plan {
public:
	// CTOR
	DietPlan();
	DietPlan(string name, int initialGoal);

	// CCTOR
	DietPlan(const DietPlan &src);

	// DTOR
	~DietPlan();
	
	// Get
	int getCalorieGoal(void);

	// PUT
	void setCalorieGoal(int goalValue);

	void editGoal(void);


protected:
	int * calorieGoal;
};


// CTOR
DietPlan::DietPlan() {
	this->calorieGoal = 0;
}

DietPlan::DietPlan(string name, int initialGoal) {

	*(this->name) = name;
	this->calorieGoal = new int(initialGoal);

}

// CCTOR
DietPlan::DietPlan(const DietPlan &src) {
	this->name = src.name;
	this->date = src.date;
	this->calorieGoal = new int(*(src.calorieGoal));
}

// DTOR
DietPlan::~DietPlan() {
	delete this->calorieGoal;
}

// Getters
int DietPlan::getCalorieGoal(void) {
	return *(this->calorieGoal);
}

// Setters
void DietPlan::setCalorieGoal(int goalValue) {
	delete this->calorieGoal;

	this->calorieGoal = new int(goalValue);
}

// Edit goal
void DietPlan::editGoal(void) {
	string name;
	int goal;
	string date;

	// Prompts user for new information and changes it accordingly
	cout << "Please enter a new name for this goal: ";
	cin >> name;
	cout << endl << "Please enter a new calorie goal for this goal: ";
	cin >> goal;
	cout << endl << "Please enter a new date for this goal: ";
	cin >> date;
	cout << endl;

	this->setName(name);
	this->setCalorieGoal(goal);
	this->setDate(date);
}
