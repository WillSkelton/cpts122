#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::array;
using std::vector;
using std::fstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::to_string;
using std::ios;

class Plan {

public:
	// Ctors
	Plan();

	// Cpy Ctors
	Plan(const Plan &src);

	// Dtor
	~Plan();
	
	// Getters
	string getName(void);
	string getDate(void);

	// Setters
	void setName(string newName);
	void setDate(string newDate);

protected:

	string * name;

	string * date;
};

#include "plan.h"


// Ctors
Plan::Plan() {
	this->name = new string("");
	this->date = new string("1/1/2000");
}

Plan::Plan(const Plan &src) {
	this->name = new string(*(src.name));
	this->date = new string(*(src.date));
}

// DTOR
Plan::~Plan() {
	delete this->date;
	delete this->name;
}

// Getters
string Plan::getName(void) {
	return *(this->name);
}
string Plan::getDate(void) {

	return *(this->date);
}

// Setters
void Plan::setName(string newName) {
	delete this->name;

	this->name = new string(newName);
}
void Plan::setDate(string newDate) {
	delete this->date;

	this->date = new string(newDate);
}