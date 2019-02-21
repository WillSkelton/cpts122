#include "Rectangle.h"


Rectangle::Rectangle() {
	mLength = 0;
	mWidth = 0;
}

Rectangle::Rectangle(int length, int width) {
	mLength = length;
	mWidth = width;
}

Rectangle::~Rectangle() {
	mLength;
	mWidth;
}

int Rectangle::getLength() {
	
	return mLength;
}

int Rectangle::getWidth() {
	
	return mWidth;
}

void Rectangle::setLength(int length) {
	mLength = (length < 0) ? 0 : length;
}

void Rectangle::setWidth(int width) {
	mWidth = (width < 0) ? 0 : width;

}
