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

	// Unique Customer number
	unsigned int customerNumber = 0;
	
	// Keeps track of how long the customer has been helped. Each iteration, this increments until
	// it's equal to the head's service time. Then the customer gets dequeued and this number increments. 
	int normalCustomerProgress = 0;
	int expressCustomerProgress = 0;

	for (int timeElapsed = 0; timeElapsed < duration; timeElapsed++) {
		int normalRange = 8 - 3 + 1;
		int expressRange = 5 - 1 + 1;
		
		// Generate random numbers
		int normalRandom = rand() % normalRange + 3;
	    int expressRandom = rand() % expressRange + 1;

		// Add Customer to normal line
		Data newNormalCustomer(customerNumber, normalRandom, timeElapsed);
		this->normal->enqueue(newNormalCustomer);
		customerNumber++;

		// Add customer to express line
		Data newExpressCusomer(customerNumber, expressRandom, timeElapsed);
		this->express->enqueue(newExpressCusomer);
		customerNumber++;

		// Check if head of normal customer line has been at the front for their service time. If yes,
		// they get dequeued and the normalCustomerProgress variable is reset to 0.
		if ((this->normal->getHead()->getData()->getServiceTime()) == normalCustomerProgress) {

			// TODO: See if I can maybe use the property on the customer object instead of normalCustomer Progress
			// to represent the time they became the head of the line.

			cout << "Customer number: [" << this->normal->getHead()->getData()->getCustomerNumber() << "] has finished checking out of the normal line." << endl;

			this->normal->dequeue();
			normalCustomerProgress = 0;
		}

		// Check if head of express customer line has been at the front for their service time. If yes,
		// they get dequeued and the expressCustomerProgress variable is reset to 0.
		if ((this->express->getHead()->getData()->getServiceTime()) == expressCustomerProgress) {

			cout << "Customer number: [" << this->express->getHead()->getData()->getCustomerNumber() << "] has finished checking out of the express line." << endl;

			this->express->dequeue();
			expressCustomerProgress = 0;
		}
		
		//cout << "====== Time Elapsed: " << timeElapsed << " minutes ======" << endl;
		//this->express->printQueue("-v");


		cout << "Customer number : [" << this->normal->getTail()->getData()->getCustomerNumber() << "] has entered the normal line." << endl;
		cout << "Customer number : [" << this->express->getTail()->getData()->getCustomerNumber() << "] has entered the express line." << endl;

		// Incremments the amount of time the customer at the front of the line has been helped 
		normalCustomerProgress++;
		expressCustomerProgress++;


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
