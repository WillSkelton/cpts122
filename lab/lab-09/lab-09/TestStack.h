#pragma once

#include "Stack.h"

template <class T>
class TestStack
{
public:
	TestStack();
	~TestStack();
	void Test(T &item1, T &item2);
	void testPostfix(string str);

private:
	Stack<T> theStack;
};

template <class T>
TestStack<T>::TestStack() : theStack(0) // this is initializing the newSize of the stack object to 0
{

}

template <class T>
TestStack<T>::~TestStack()
{

}

template <class T>
void TestStack<T>::Test(T &item1, T &item2)
{
	//cout << "peek: " << item2 << endl;
	theStack.push(item1);
	theStack.peek(item2);
	cout << "peek: " << item2 << endl;
}
template <class T>
void TestStack<T>::testPostfix(string str){
	this->theStack.postfixEval(str);
}