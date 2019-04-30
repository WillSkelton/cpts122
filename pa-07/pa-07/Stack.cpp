#include "Stack.h"


// Ctor
Stack::Stack(){
	this->length = 0;
	this->top = new vector<string>;
}

Stack::Stack(string initial){
	this->length = 0;
	this->top = new vector<string>;
	this->push(initial);
}

// Dtor
Stack::~Stack(){}

string Stack::peek(void){

	string recent = "N/A";
	
	if (this->top->empty() == false) {
		recent = (*this->top)[0];
	}

	return recent;

}

string Stack::pop(void){
	string temp = (*this->top)[0];

	this->top->erase(this->top->begin());
	
	this->length--;

	return temp;

}

int Stack::push(string absence){

	this->top->insert(this->top->begin(), absence);
	this->length++;

	return this->length;

}


int Stack::getLength(void) {
	return this->length;
}
