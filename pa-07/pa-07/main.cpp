
#include "Stack.h"


int main(void) {

	Stack myStack;

	myStack.push("One");

	cout << "Top: " << myStack.peek() << " | Length: " << myStack.getLength() << endl;

	myStack.push("two");

	cout << "Top: " << myStack.peek() << " | Length: " << myStack.getLength() << endl;

	myStack.push("three");

	cout << "Top: " << myStack.peek() << " | Length: " << myStack.getLength() << endl;

	myStack.pop();

	cout << "Top: " << myStack.peek() << " | Length: " << myStack.getLength() << endl;

	

	return 0;
}