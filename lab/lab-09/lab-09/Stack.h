// This file contains a stack class template. The underlying data structure for the 
// stack is an array allocated from the heap.

#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T &newItem); 
	bool pop(T &poppedItem);
	bool peek(T &item);

	bool isEmpty(void);

	bool postfixEval(string &str);

	bool hasSpace(void);
	int getLength(void);
	int getMaxLength(void);

	void changeLength(int modifier);


private:
	int mSize; // represents the current number of items in the stack
	int mMaxSize; // must not exceed the max size of our allocated array
	T *mTop; // will point to contigous memory on the heap (an array)
};

template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize; // this can also be used as the index to the top of the stack
	mMaxSize = 100;
	mTop = new T[100]; // allocating an array of 100 items of type T on the heap
}

template <class T>
Stack<T>::~Stack()
{
	delete[] mTop; // this is how we free up an array on the heap in C++
}

// Places the newItem at the top of the stack
template <class T>
bool Stack<T>::push(T &newItem)
{
	bool success = false;
	
	if (hasSpace() == true) {
		
		this->mTop[getLength()] = newItem;
		
		this->changeLength(1);
		success = true;
	}

	return success;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you pop. Places the popped item in 
// the parameter referred to as "poppedItem". Returns true if the item was popped; false
// otherwise.
template <class T>
bool Stack<T>::pop(T &poppedItem)
{
	bool success = false;

	if (isEmpty() == false) {
		this->changeLength(-1);
		poppedItem = this->mTop[this->getLength()];
		success = true;
	}

	return success;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you peek. Places the item at the top of the
// stack in the parameter referred to as "item". Returns true if there
// is an item at the top; false otherwise.
template <class T>
bool Stack<T>::peek(T &item)
{
	bool success = false;
	
	if (this->isEmpty() == false) {
		item = this->mTop[this->getLength() - 1];
		success = true;
	}

	return success;
}

// Returns true if the stack is empty; false otherwise
template <class T>
bool Stack<T>::isEmpty()
{
	return (this->getLength() == 0) ? true : false;
}

template <class T>
int Stack<T>::getLength(void) {
	return this->mSize;
}

template <class T>
int Stack<T>::getMaxLength(void) {

	return this->mMaxSize;
}

template <class T>
bool Stack<T>::hasSpace(void) {
	return (this->getLength() < this->getMaxLength()) ? true : false;
}

template <class T>
void Stack<T>::changeLength(int modifier) {
	this->mSize += modifier;
}

template <class T>
bool Stack<T>::postfixEval(string &str) {
	int num1 = str[0];
	int num2 = str[0];
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {

		cout << "str[i]: " << str[i] << endl;
		cout << "Stack: " << this->mTop << endl;

		if (str[i] >= '0' && str[i] <= '9') {
			temp = (str[i] - '0');
			this->push(temp);
		}
		else {

			switch (str[i]) {
			case('*'):
				this->pop(num2);
				this->pop(num1);
				temp = (num1 * num2);
				this->push(temp);
				break;

			case('/'):
				this->pop(num2);
				this->pop(num1);
				temp = (num1 / num2);
				this->push(temp);
				break;

			case('+'):
				this->pop(num2);
				this->pop(num1);
				temp = (num1 + num2);
				this->push(temp);
				break;

			case('-'):
				this->pop(num2);
				this->pop(num1);
				temp = (num1 - num2);
				this->push(temp);
				break;

			default:
				break;
			}
		}
	}
	cout << this->mTop[0];
	return false;
}

