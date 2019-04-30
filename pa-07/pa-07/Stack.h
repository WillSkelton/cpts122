#include "dependencies.h";

class Stack {

public:
	// Ctor
	Stack();
	Stack(string initial);

	// Dtor
	~Stack();

	string peek(void);

	string pop(void);

	int push(string absence);

	int getLength(void);

	

private:
	vector<string> *top;

	int length;

};