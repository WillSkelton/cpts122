#include "Wrapper.h"


Wrapper::Wrapper(){
	this->express = new Queue();
	this->normal = new Queue();
};

Wrapper::~Wrapper(){
	delete this->express;
	delete this->normal;
};

void Wrapper::REPL(void){

	int choice = 0;
	while (choice != 3) {
		choice = this->printMenu();

		switch (choice) {

		case 1:
			cout << "Starting Simulation..." << endl;
			break;

		case 2:
			cout << "Starting Tests" << endl;
			break;

		case 3:
			cout << "Goodbye" << endl;
			break;

		default:
			cout << "I don't know how you got here" << endl;
			break;
		}


	}

};

int Wrapper::printMenu(void) {
	int choice = 0;
	// Prints menu and makes sure user chooses a valid menu option
	do {
		system("cls");
		cout << "1.) Run Simulation." << endl
			<< "2.) Run Tests." << endl
			<< "3.) Exit." << endl
			<< ">>> ";
		cin >> choice;

	} while (choice < 1 || choice > 3);



	cout << choice << endl;

	// Returns user input
	return choice;
}

void Wrapper::runSimulation(void){};

// Tests
bool Wrapper::runAllTests(void){
	return false;
};

bool Wrapper::basicTest(void){
	Data d1 = Data(1, 10, 20);
	Data d2 = Data(2, 20, 40);
	Data d3 = Data(3, 30, 60);
	Data d4 = Data(4, 40, 80);
	Data d5 = Data(5, 50, 100);

	Queue myQueue = Queue(d1);
	myQueue.printQueue("-v");

	cout << endl << "D2" << endl << endl;;

	myQueue.enqueue(d2);
	myQueue.printQueue("-v");

	cout << endl << "D3" << endl << endl;;

	myQueue.enqueue(d3);
	myQueue.printQueue("-v");

	cout << endl << "Dequeue D1" << endl << endl;;

	myQueue.dequeue();
	myQueue.printQueue("-v");
	return true;
};
