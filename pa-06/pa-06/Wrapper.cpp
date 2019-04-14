#include "Wrapper.h"


// CTOR
Wrapper::Wrapper() {
	this->morseTable = new BST();
}


// DTOR
Wrapper::~Wrapper() {}


// REPL
void Wrapper::REPL(void) {

	string message = "";

	do {

		cout << "Please enter a phrase to translate into morse code or type `exit!` to quit:" << endl
			<< ">>> ";

		cin >> message;

		cout << "You entered: `" << message << "`" << endl;

		if (message == "exit!") {
			cout << "Goodbye" << endl;
			break;
		}

		this->morseTable->addNode('2', "-");
		this->morseTable->addNode('3', ".-- -");
		this->morseTable->addNode('5', ".");
		this->morseTable->addNode('#', ".");
		this->morseTable->addNode('4', "...--");
		this->morseTable->addNode('1', ".-");


		this->morseTable->addNode('A', "-- -");

		this->morseTable->printTreeInOrder();



	} while (message != "exit!");

}

string Wrapper::translate(string message) {
	string translation = " ";

	for (int i = 0; i < message.length(); i++) {

	}

	return translation;
}

// Fill File
void Wrapper::fillTree(void) {

}