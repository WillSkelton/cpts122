#include "Data.h"

// Ctor:
Data::Data(){}
Data::Data(int recordNumber, int ID, string name, string email, int units, string program, int year, int numAbsences) {

	string levels[5] = { "freshman", "sophomore", "junior", "senior", "graduate" };

	this->recordNumber = recordNumber;
	this->ID = ID;
	this->name = name;
	this->email = email;
	this->units = units;
	this->program = program;
	this->year = levels[year];
	this->numAbsences = numAbsences;
	this->absences = new Stack();
}


// Dtor
Data::~Data(){
	delete this->absences;
}

// Getters
int Data::getRecordNumber(void){
	return this->recordNumber;
}

int Data::getID(void){
	return this->ID;
}

string Data::getName(void){
	return this->name;
}

string Data::getEmail(void){
	return this->email;
}

int Data::getUnits(void){
	return this->units;
}

string Data::getProgram(void){
	return this->program;
}

string Data::getYear(void){
	return this->year;
}

int Data::getNumAbsences(void){
	return this->numAbsences;
}

Stack *Data::getAbsences(void){
	return this->absences;
}


void Data::setRecordNumber(int recordNumber){
	this->recordNumber = recordNumber;
}

void Data::setID(int ID){
	this->ID = ID;
}

void Data::setName(string name){
	this->name = name;
}

void Data::setEmail(string email){
	this->email = email;
}

void Data::setUnits(int units){
	this->units = units;
}

void Data::setProgram(string program){
	this->program = program;
}

void Data::setYear(string year){
	this->year = year;
}

void Data::setNumAbsences(int numAbsences){
	this->numAbsences = numAbsences;
}

