#include "Rectangle.h"


int Rectangle::getLength() {
	
	return mLength;
}

int Rectangle::getWidth() {
	
	return mLength;
}

void Rectangle::setLength(int length) {
	mLength = (length < 0) ? 0 : length;
}

void Rectangle::setWidth(int width) {
	mWidth = (width < 0) ? 0 : width;

}