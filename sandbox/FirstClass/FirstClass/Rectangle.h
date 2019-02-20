#pragma once

#include <iostream>
using namespace std;

class Rectangle {

public:

	Rectangle();
	
	Rectangle(int length, int width);

	~Rectangle();

	int getLength();
	int getWidth();

	void setLength(int length);
	void setWidth(int width);

private:

	int mLength;
	int mWidth;
};