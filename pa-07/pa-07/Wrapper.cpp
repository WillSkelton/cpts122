#include "Wrapper.h"

// CTOR
Wrapper::Wrapper(){
	//this->openFiles();
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

// Main Menu Loop
void Wrapper::REPL(void){
	int choice = 0;

	do {
		system("cls");

		this->printMenu();

		choice = inputCheck(1, 6);

		this->router(choice);


	} while (choice != 6);

}

// Makes sure user's choice is between 2 numbers
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

// routes user's menu choice to a function
void Wrapper::router(int choice) {

	switch (choice) {
	case 1:
		this->import();
		system("pause");
		break;

	case 2:
		this->load();
		system("pause");
		break;

	case 3:
		this->store();
		break;

	case 4:
		this->markAbsences();
		break;

	case 5:
		this->generateReports();
		break;

	case 6:

		cout << "Goodbye!" << endl;
		break;

	default:
		cout << "Idk how you got here...";
		break;

	}
}

// Opens all files. Not Used
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

// Closes all file. Not used
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

// Print's main menu
void Wrapper::printMenu(void){
	cout << "1. Import course list" << endl
		<< "2. Load master list" << endl
		<< "3. Store master list" << endl
		<< "4. Mark absences" << endl
		<< "5. Generate report" << endl
		<< "6. Exit" << endl;
}

// Impots files from classList.csv
void Wrapper::import(void){
	
	this->classList.nukeList();

	this->read(this->infile, "classList.csv");
}

// takes a fstream and a filename and reads the contents of that file to the wrapper class's list
void Wrapper::read(fstream &infile, string filename) {
	infile.open(filename, ios::in);

	Data *temp;
	string line = "";

	int recordNumber = 0;
	int id = 0;
	string name = "";
	string email = "";
	int units = 0;
	string program = "";
	string level = "";

	// Gobble the first line
	getline(infile, line);
	getline(infile, line, ',');
	recordNumber = std::stoi(line);


	while (infile.eof() != 1) {

		getline(infile, line, ',');
		id = std::stoi(line);

		getline(infile, line, '"');
		getline(infile, line, '"');
		name = line;

		getline(infile, line, ',');
		getline(infile, line, ',');
		email = line;

		getline(infile, line, ',');
		units = (line == "AU") ? -1 : std::stoi(line);

		getline(infile, line, ',');
		program = line;

		getline(infile, line, '\n');
		level = line;

		getline(infile, line, ',');

		temp = new Data(recordNumber, id, name, email, units, program, level, 0);

		this->classList.prepend(temp);
		//this->classList.print();

		recordNumber++;
		//cout << "==================" << endl;

	}
	this->classList.print();
	infile.close();
}

// Does basically the same thing as import but for the masterfile
void Wrapper::load(void){

	this->classList.nukeList();
	
	this->read(this->masterFile, "masterFile.txt");

}

// Saves the contents of the wrapper class's list to the materfile
void Wrapper::store(void){

	if (this->classList.getLength() > 0) {
		this->masterFile.open("masterFile.txt", ios::out);
		this->classList.print2File(this->masterFile);
		this->masterFile.close();
	}

}

// goes through each student and asks the user if they want to add today's date to the student's absence list
void Wrapper::markAbsences(void){

	Node<string> *temp = this->classList.getHead();


	auto now = std::chrono::system_clock::now();

	std::time_t date = std::chrono::system_clock::to_time_t(now);

	string today = std::ctime(&date);
	today = today.substr(0, 10);

	std::cout << "Today's date is: " << today << endl;

	//system("pause");


	while (temp != nullptr) {
		
		int isAbsent = 0;

		cout << "Do you want to mark '" << temp->getData()->getName() << "' as absent?" << endl
			<< "1. Yes" << endl
			<< "2. No" << endl;
		isAbsent = inputCheck(1, 2);

		if (isAbsent == 1) {
			temp->getData()->getAbsences()->push(today);
		}

		temp = temp->getNext();
	}

}

// Asks the user which report the want to generate and generates the corresponding report
void Wrapper::generateReports(void){

	int choice;
	int threshold = 0;

	cout << "Would you like to..." << endl
		<< "1. Generate report for all students; showing only the most recent absence for each student" << endl
		<< "2. Generate report for students with absences that match or exceed a certain number of absences" << endl
		<< "3. Cancel" << endl;

	choice = inputCheck(1, 3);

	switch (choice) {
	case 1:
		this->report1.open("report1.txt", ios::out);
		this->classList.reportOne(this->report1);
		this->report1.close();
		break;

	case 2:
		cout << "Absence threshold:" << endl << ">>> ";
		cin >> threshold;
		
		//this->report1.open("report1.txt", ios::out);
		//cout << this->report1.is_open() << endl;

		this->report2.open("report2.txt", ios::out);
		cout << this->report2.is_open() << endl;

		

		this->classList.reportTwo(threshold, this->report2);
		this->report2.close();
		break;

	case 3:
		break;

	default:
		cout << "idk how you wound up here" << endl;
		break;
	}


}
