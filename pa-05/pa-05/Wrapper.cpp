#include "Wrapper.h"
#include <math.h>


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
			this->runSimulation(30);
			this->cleanQueues();
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

void Wrapper::cleanQueues(void) {
	delete this->normal;
	delete this->express;
	this->express = new Queue();
	this->normal = new Queue();
}


void Wrapper::runSimulation(int duration){

	int customerNumber = 0;

	for (int timeElapsed = 0; timeElapsed < duration; timeElapsed++) {
		int normalRange = 8 - 3 + 1;
		int expressRange = 5 - 1 + 1;
		
		// Generate random numbers
		int normalRandom = rand() % normalRange + 3;
	    int expressRandom = rand() % expressRange + 1;


		//cout << "normalRandom: " << normalRandom << endl;

		// Add Customer to normal line
		Data newNormalCustomer(customerNumber, normalRandom, timeElapsed);
		this->normal->enqueue(newNormalCustomer);
		customerNumber++;

		// Add customer to express line
		Data newExpressCusomer(customerNumber, expressRandom, timeElapsed);
		this->express->enqueue(newExpressCusomer);
		customerNumber++;

		// Check if customer is done
		if (((this->normal->getHead()->getData()->getServiceTime()) + (this->normal->getHead()->getData()->getTotalTime())) <= timeElapsed) {
			this->normal->dequeue();
		
		}

		if (((this->express->getHead()->getData()->getServiceTime()) + (this->express->getHead()->getData()->getTotalTime())) <= timeElapsed) {
			this->express->dequeue();
		}
		
		cout << " ====== Time Elapsed: " << timeElapsed << " minutes ======" << endl;
		this->normal->printQueue("-v");


		//cout << expressRandom << endl;
	}
	system("pause");

};

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

	Queue myQueue = Queue();
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
