#include "Wrapper.h"

// CTOR
Wrapper::Wrapper() {
	this->morseTable = new BST();
}


// DTOR
Wrapper::~Wrapper() {}


// REPL
void Wrapper::REPL(void) {
	
	// Opens morse table file and fills the BST with the contents
	this->fillTree();

	// Prints the tree
	this->morseTable->printTreeInOrder();

	// Translates the file
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

	// iterates through one line of the file and converts each character to it's morse 
	// translation. Spaces are converted into 3 spaces and newline chars get copied over
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
			// Looks up letter, appends it to the string, and then prints the letter
			morseLetter = this->morseTable->lookup(uppercase[i]);
			morseTranslation += morseLetter;
			cout << morseLetter;

			// if the next char isn't a space, it prints a single space
			if (uppercase[i + 1] != ' ') {
				morseTranslation += ' ';
				cout << ' ';
			}

			break;
		}
	}
	cout << endl;
	// returns morse translation. Not used but could be later.
	return morseTranslation;
}

string Wrapper::translateFile(void) {

	// Opens file
	fstream message;
	message.open("Convert.txt", ios::in);

	string line;
	string morse;

	cout << "Morse Translation: " << endl;

	// While not at the end of the file...
	while (message.eof() != 1) {

		// Gets one line of the file
		getline(message, line);

		// converts it
		morse += this->translate(line);

		// Appends a newline char after each line
		morse += '\n';
	}
	
	// closes file
	message.close();
	return morse;
}

// Fill File
void Wrapper::fillTree(void) {

	// Opens file
	fstream table;
	table.open("MorseTable.txt", ios::in);


	char letter;
	string morse;
	string line;

	// While not at the end of the file...
	while (table.eof() != 1) {

		// Gets letter
		getline(table, line, ':');
		letter = line[0];
		
		// gets morse string
		getline(table, line, '\n');
		morse = line;

		//cout << letter << ": " << morse << endl;

		// adds both to the BST
		this->morseTable->addNode(letter, morse);
	}

	// Closes file
	table.close();
}

string Wrapper::toUpper(string str) {
	
	string upper = "";

	// Iterates through a string and shifts all lowercase letters to uppercase
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			upper += (str[i] - 32);
		}
		else {
			upper += str[i];
		}
	}
	return upper;
}
