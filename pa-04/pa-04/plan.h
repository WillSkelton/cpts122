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
	Plan(int month, int day, int year);

	// Cpy Ctors
	Plan(Plan &src);

	// Dtor
	~Plan();
	
	// Getters
	int getGoal(void);
	string getname(void);
	string getDate(void);

	// Setters
	void setGoal(int newGoal);
	void setName(string newName);
	void setDate(int month, int day, int year);

private:

	int goal;

	string name;

	int date[3];
};