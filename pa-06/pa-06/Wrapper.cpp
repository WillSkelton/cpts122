#include "Wrapper.h"


// CTOR
Wrapper::Wrapper() {
	this->morseTable = new BST();
}


// DTOR
Wrapper::~Wrapper() {}


// REPL
void Wrapper::REPL(void) {

	string userChoice = "";

	do {

		cout << "Please enter a phrase to translate into morse code or type `exit!` to quit:" << endl
			<< ">>> ";

		cin >> userChoice;

		cout << "You entered: `" << userChoice << "`" << endl;

		if (userChoice == "exit!") {
			cout << "Goodbye" << endl;
			break;
		}

	} while (userChoice != "exit!");

}