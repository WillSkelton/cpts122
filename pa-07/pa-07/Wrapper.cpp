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

void Wrapper::REPL(void){
	int choice = 0;

	do {
		system("cls");

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
		this->import();

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
	
	this->classList.nukeList();

	this->read(this->infile, "classList.csv");
}

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

		if (name == "Mort,Kris") {
			cout << line << endl;
		}
		getline(infile, line, ',');


		temp = new Data(recordNumber, id, name, email, units, program, level, 0);

		this->classList.prepend(temp);
		//this->classList.print();

		recordNumber++;
		cout << "==================" << endl;

	}
	infile.close();
}

void Wrapper::load(void){

	this->classList.nukeList();
	
	this->read(this->masterFile, "masterFile.txt");

}

void Wrapper::store(void){

	if (this->classList.getLength() > 0) {
		this->masterFile.open("masterFile.txt", ios::out);
		this->classList.print2File(this->masterFile);
		this->masterFile.close();
	}

}

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
		isAbsent = inputCheck(0, 1);

		if (isAbsent == 1) {
			temp->getData()->getAbsences()->push(today);
		}

		temp = temp->getNext();
	}

}

void Wrapper::generateReport(void){}
