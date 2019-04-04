#include "Queue.h"

// CTORS
Queue::Queue() {
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}

Queue::Queue(Data &newData) {
	QueueNode *firstNode = new QueueNode(newData);
	this->head = firstNode;
	this->tail = firstNode;
	this->length = 1;
}

Queue::Queue(QueueNode &newNode) {
	this->head = &(newNode);
	this-> tail = &(newNode);
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

	for (int i = 0; i < this->getLength(); i++) {
		if (idx != nullptr) {
			cout << "Butt Number: " << idx->getData()->getCustomerNumber() << endl
				<< "Service Time: " << idx->getData()->getServiceTime() << endl
				<< "Total Time: " << idx->getData()->getTotalTime() << endl
				<< "=====================================================================================" << endl;
			idx = idx->getNextNode();
		}
	}

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

