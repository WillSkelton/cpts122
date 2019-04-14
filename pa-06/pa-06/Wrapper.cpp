#include "Wrapper.h"


// CTOR
Wrapper::Wrapper() {
	this->morseTable = new BST();
}


// DTOR
Wrapper::~Wrapper() {}


// REPL
void Wrapper::REPL(void) {
	
	this->fillTree();

	this->morseTable->printTreeInOrder();

	string morse = this->translateFile();

	/*string message = "";
	do {

		cout << "Please enter a phrase to translate into morse code or type `exit!` to quit:" << endl
			<< ">>> ";

		cin >> message;

		cout << "You entered: `" << message << "`" << endl;

		if (message == "exit!") {
			cout << "Goodbye" << endl;
			break;
		}

		this->translate(message);



	} while (message != "exit!");*/

}

string Wrapper::translate(string message) {
	string morseTranslation = "";
	string morseLetter = "";
	string uppercase = this->toUpper(message);

	for (int i = 0; i < uppercase.length(); i++) {
		
		switch (uppercase[i]) {
		case ' ':
			morseTranslation += "   ";
			cout << "   ";
			break;

		case '\n':
			morseTranslation += '\n';
			cout << endl;
			break;

		default:
			morseLetter = this->morseTable->lookup(uppercase[i]);
			morseTranslation += morseLetter;
			cout << morseLetter;

			if (uppercase[i + 1] != ' ') {
				morseTranslation += ' ';
				cout << ' ';
			}

			break;

		}

	}
	cout << endl;

	return morseTranslation;
}

string Wrapper::translateFile(void) {
	fstream message;
	message.open("Convert.txt", ios::in);

	string line;
	string morse;

	cout << "Morse Translation: " << endl;

	while (message.eof() != 1) {
		getline(message, line);
		morse += this->translate(line);
		morse += '\n';
	}


	//cout << morse << endl;

	message.close();
	return morse;
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

	//cout << upper << endl;

	return upper;
}
