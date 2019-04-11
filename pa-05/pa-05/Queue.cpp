#include "Queue.h"
#include <string>

using std::string;

// CTORS
Queue::Queue(string name) {

	this->name = name;
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}

Queue::Queue(Data &newData, string name) {
	QueueNode *firstNode = new QueueNode(newData);

	this->name = name;
	this->head = firstNode;
	this->tail = firstNode;
	this->length = 1;
}

Queue::Queue(QueueNode &newNode, string name) {
	
	this->name = name;
	this->head = &(newNode);
	this->tail = &(newNode);
	this->length = 1;
}

// CCTOR
Queue::Queue(Queue &src) {

}

// DTOR
Queue::~Queue() {
	delete this->head;
	// delete this->tail;
}

// Getters
int Queue::getLength(void) {
	return this->length;
}

QueueNode * Queue::getHead(void) {
	return this->head;
}

QueueNode * Queue::getTail(void) {
	return this->tail;
}

void Queue::incOrDecLength(int modifier) {
	this->length += modifier;
}

//void Queue::setHead(QueueNode *newHead) {}
//
//void Queue::setTail(QueueNode *newTail) {}

// Queue Methods
bool Queue::enqueue(Data &newData) {
	QueueNode *tempNode = new QueueNode(newData);

	if (this->head == nullptr) {
		this->head = tempNode;
		this->tail = tempNode;
		this->incOrDecLength(1);
	}
	else {
		this->tail->setNext(tempNode);
		this->tail = tempNode;
		this->incOrDecLength(1);
	}

	return false;
}

bool Queue::dequeue(void) {
	QueueNode *tempNode = this->head;
	this->head = this->head->getNextNode();
	tempNode->setNext(nullptr);
	delete tempNode;
	this->incOrDecLength(-1);

	return false;
}

bool Queue::printQueue() {

	QueueNode *idx = this->head;

	cout << this->name << " Line" << endl;

	cout << "| Customer Number | Service Time | Time Arrived |" << endl;
	cout << "| :-------------: | :----------: | :----------: |" << endl;

	for (int i = 0; i < this->getLength(); i++) {
		if (idx != nullptr) {

			if (idx->getData()->getCustomerNumber() < 10) {
				cout << "|      " << idx->getData()->getCustomerNumber() << "          |     " << idx->getData()->getServiceTime() << "        |     "; //<< idx->getData()->getTotalTime() << "            | " << endl;

			}
			else {
				cout << "|      " << idx->getData()->getCustomerNumber() << "         |     " << idx->getData()->getServiceTime() << "        |     ";// << idx->getData()->getTotalTime() << "            | " << endl;

			}

			if (idx->getData()->getTotalTime() < 10) {
				cout << idx->getData()->getTotalTime() << "        |" << endl;
			}
			else {
				cout << idx->getData()->getTotalTime() << "       |" << endl;
			}

			idx = idx->getNextNode();
		}
	}
	cout << endl << endl;


	return false;
}

bool Queue::printQueue(string tag) {

	if (tag == "-v") {
		QueueNode *idx = this->head;

		cout << "Queue Length: " << this->getLength() << endl
			<< "-------------" << endl;

		for (int i = 0; i < this->getLength(); i++) {
			if (idx != nullptr) {
				cout << "Customer Number: " << idx->getData()->getCustomerNumber() << endl
					<< "Service Time: " << idx->getData()->getServiceTime() << endl
					<< "Total Time: " << idx->getData()->getTotalTime() << endl
					//<< "=======================================" 
					<< endl;
				idx = idx->getNextNode();
			}
		}
	}
	
	return false;
}

