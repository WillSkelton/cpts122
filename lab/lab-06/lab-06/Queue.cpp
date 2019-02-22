#include "Queue.h"
// ==================== Queue Methods ====================
// ============ CTORs ============
Queue::Queue() {
	head = nullptr;
	tail = nullptr;

	this->length = 0;
}

Queue::Queue(string str) {
	head = nullptr;
	tail = nullptr;

	Node *n = new Node(str);

	this->head = n;
	this->tail = n;

	this->length = 1;
}

// ============ DCTOR ============
Queue::~Queue() {
	delete head;
	delete tail;
}


void Queue::enqueue(string newStr) {

	Node *newNode = new Node(newStr);

	if (this->head == nullptr || this->tail == nullptr) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		this->tail->next = newNode;
		this->tail = newNode;
	}
	
	this->length++;
}

void Queue::printQueueL2R(void) {
	
	Node *tempNode = this->head;
	string tempStr = "";

	while (tempNode != nullptr) {
		tempStr = tempNode->getString();
		cout << tempNode->getString() << " --> ";

		tempNode = tempNode->next;
	}
}

void Queue::printQueueL2RRec(Node *node) {
	if (node->next != nullptr) {
		cout << (node->getString()) << " --> ";
		printQueueL2RRec(node->next);
		
	}
	else {
		cout << (node->getString()) << " --> ";
		return;
	}

	//cout << "\n";
}

void Queue::dequeue(void) {

}




int Queue::getLength(void) {
	return this->length;
}

Queue::Node* Queue::getHead(void) {
	return this->head;
}


// ==================== Node Methods ====================
Queue::Node::Node(string str) {
	this->str = str;
	this->next = nullptr;
}

string Queue::Node::getString() {
	return this->str;
}