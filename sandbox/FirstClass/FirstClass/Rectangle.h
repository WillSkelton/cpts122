#pragma once

#include <iostream>

class Rectangle {

public:

	int getLength();
	int getWidth();

	void setLength(int length);
	void setWidth(int width);

private:

	int mLength;
	int mWidth;
};