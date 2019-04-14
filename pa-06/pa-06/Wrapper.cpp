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

		/*cout << "Please enter a phrase to translate into morse code or type `exit!` to quit:" << endl
			<< ">>> ";

		cin >> message;

		cout << "You entered: `" << message << "`" << endl;

		if (message == "exit!") {
			cout << "Goodbye" << endl;
			break;
		}*/

		this->fillTree();

		//this->morseTable->printTreeInOrder();

		this->translate("HeLlO wOrLd");

		// cout << "A: " << this->morseTable->lookup('A') << endl;

		message = "exit!";

	} while (message != "exit!");

}

string Wrapper::translate(string message) {
	string translation = " ";

	string uppercase = this->toUpper(message);

	for (int i = 0; i < uppercase.length(); i++) {
		
		switch (uppercase[i]) {
		case ' ':
			cout << "   ";
			break;

		case '\n':
			cout << endl;
			break;

		default:
			cout << this->morseTable->lookup(uppercase[i]);

			if (uppercase[i + 1] != ' ') cout << ' ';
			
			break;

		}

	}
	cout << endl;

	return translation;
}

// Fill File
void Wrapper::fillTree(void) {
	fstream table;
	table.open("MorseTable.txt", ios::in);


	char letter;
	string morse;
	string line;

	while (table.eof() != 1) {

		getline(table, line, ':');
		letter = line[0];
		
		getline(table, line, '\n');
		morse = line;

		//cout << letter << ": " << morse << endl;

		this->morseTable->addNode(letter, morse);
	}

	table.close();
}

string Wrapper::toUpper(string str) {
	
	string upper = "";

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			upper += (str[i] - 32);
		}
		else {
			upper += str[i];
		}
	}

	cout << upper << endl;

	return upper;
}
