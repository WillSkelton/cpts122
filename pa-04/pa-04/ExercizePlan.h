#pragma once
#include "plan.h"

class ExercizePlan : public Plan {
public:
	// CTOR
	ExercizePlan();
	ExercizePlan(string name, int initialGoal);

	// CCTOR
	ExercizePlan(const ExercizePlan &src);

	// DTOR
	~ExercizePlan();

	// Get
	int getStepGoal(void);

	// PUT
	void setStepGoal(int goalValue);
	void editGoal(void);

protected:
	int * stepGoal;
};

// CTOR
ExercizePlan::ExercizePlan() {
	this->stepGoal = 0;
}

ExercizePlan::ExercizePlan(string name, int initialGoal){

	*(this->name) = name;
	this->stepGoal = new int(initialGoal);
}

// CCTOR
ExercizePlan::ExercizePlan(const ExercizePlan &src){
	this->date = src.date;
	this->name = src.name;
	this->stepGoal = new int(*(src.stepGoal));
}

// DTOR
ExercizePlan::~ExercizePlan(){
	delete this->stepGoal;
}

// Getter
int ExercizePlan::getStepGoal(void){
	return *(this->stepGoal);
}

// Setter
void ExercizePlan::setStepGoal(int goalValue){
	delete this->stepGoal;
	
	this->stepGoal = new int(goalValue);

}

// Edit Goal
void ExercizePlan::editGoal(void) {
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
	this->setStepGoal(goal);
	this->setDate(date);
}