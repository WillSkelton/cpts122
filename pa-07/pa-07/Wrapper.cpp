#include "Wrapper.h"

// CTOR
Wrapper::Wrapper(){
	this->openFiles();
}

// DTOR
Wrapper::~Wrapper(){
	this->closeFiles();
	
	//delete this->classList;
}

// Start App
void Wrapper::startApp(void){
	this->REPL();
}

void Wrapper::REPL(void){
	int choice = 0;

	do {

		this->printMenu();

		choice = inputCheck(1, 6);

		this->router(choice);


	} while (choice != 6);

}

int Wrapper::inputCheck(int lower, int upper) {
	int choice = lower - 1;

	while (choice < lower || choice > upper) {
		cout << ">>> ";
		cin >> choice;

		if (choice < lower || choice > upper) {
			cout << "Please enter an integer between " << lower << " and " << upper << endl;
		}
	}

	return choice;
}

void Wrapper::router(int choice) {

	switch (choice) {
	case 1:
		cout << "1. Import course list" << endl;
		this->import();

		break;

	case 2:
		cout << "2. Load master list" << endl;
		break;

	case 3:
		cout << "3. Store master list" << endl;
		break;

	case 4:
		cout << "4. Mark absences" << endl;
		break;

	case 5:
		cout << "5. Generate report" << endl;
		break;

	case 6:

		cout << "Goodbye!" << endl;
		break;

	default:
		cout << "Idk how you got here...";
		break;

	}
}

void Wrapper::openFiles(void){
	// Infile
	if (this->infile.is_open() == false) {
		this->infile.open("classList.csv", ios::in);
	}
	else {
		this->infile.close();
		this->infile.open("classList.csv", ios::in);
	}

	// Report 1
	if (this->report1.is_open() == false) {
		this->report1.open("report1.txt", ios::out);
	}
	else {
		this->report1.close();
		this->report1.open("report1.txt", ios::out);
	}

	// Report 2
	if (this->report2.is_open() == false) {
		this->report2.open("report2.txt", ios::out);
	}
	else {
		this->report2.close();
		this->report2.open("report2.txt", ios::out);
	}

}

void Wrapper::closeFiles(void){
	// Infile
	if (this->infile.is_open() == true) {
		this->infile.close();
	}

	// Report 1
	if (this->report1.is_open() == true) {
		this->report1.close();
	}

	// Report 2
	if (this->report2.is_open() == true) {
		this->report2.close();
	}
}

void Wrapper::printMenu(void){
	cout << "1. Import course list" << endl
		<< "2. Load master list" << endl
		<< "3. Store master list" << endl
		<< "4. Mark absences" << endl
		<< "5. Generate report" << endl
		<< "6. Exit" << endl;
}

void Wrapper::import(void){
	this->openFiles();

	Node<string> *temp;
	string line = "";

	int id = 0;
	string name = "";
	string email = "";
	int units = 0;
	string program = "";
	string level = "";

	// Gobble the first line
	getline(this->infile, line);
	getline(this->infile, line, ',');


	while (this->infile.eof() != 1) {
		
		getline(this->infile, line, ',');
		id = std::stoi(line);

		getline(this->infile, line, '"');
		getline(this->infile, line, '"');
		name = line;

		getline(this->infile, line, ',');
		getline(this->infile, line, ',');
		email = line;

		getline(this->infile, line, ',');
		units = (line == "AU") ? -1 : std::stoi(line);

		getline(this->infile, line, ',');
		program = line;

		getline(this->infile, line, '\n');
		level = line;

		if (name == "Mort,Kris") {
			cout << line << endl;
		}
		getline(this->infile, line, ',');

		cout << this->infile.eof() << endl;

	}



	//Node(int recordNumber, int ID, string name, string email, int units, string program, int year, int numAbsences, Stack *absences);


}

void Wrapper::load(void){}

void Wrapper::store(void){}

void Wrapper::markAbsences(void){}

void Wrapper::generateReport(void){}
