#include "Data.h"

// CTORS:
// Data::Data(){}
Data::Data(int customerNumber, int serviceTime, int totalTime) {
	this->customerNumber = customerNumber;
	this->serviceTime = serviceTime;
	this->totalTime = totalTime;
}

Data::Data(Data &src) {
	this->customerNumber = src.customerNumber;
	this->serviceTime = src.serviceTime;
	this->totalTime = src.totalTime;
}

// Getters:
int Data::getCustomerNumber(void) {
	return this->customerNumber;
}

int Data::getServiceTime(void) {
	return this->serviceTime;
}

int Data::getTotalTime(void) {
	return this->totalTime; 
}


// Setters
void Data::setCustomerNumber(int newCustomerNumber) {
	this->customerNumber = newCustomerNumber;
}

void Data::setServiceTime(int newServiceTime) {
	this->serviceTime = newServiceTime;
}

void Data::setTotalTime(int newTotalTime) {
	this->totalTime = newTotalTime;
}
