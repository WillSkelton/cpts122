#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using std::cout;
using std::string;
using std::endl;
using std::array;
using std::vector;


class Plan {

public:
	// Ctors
	Plan();

	// Cpy Ctors
	Plan(Plan &src);

	// Dtor
	//~Plan();
	
	// Getters
	string getName(void);
	string getDate(void);

	// Setters
	void setName(string newName);
	void setDate(string newDate);

protected:

	string name;

	string date;
};

#include "plan.h"


// Ctors
Plan::Plan() {
	this->name = "";
	this->date = "1/1/2000";
}

string Plan::getName(void) {
	return this->name;
}

string Plan::getDate(void) {

	return this->date;
}

// Setters
void Plan::setName(string newName) {

}
void Plan::setDate(string newDate) {
	this->date = newDate;
}