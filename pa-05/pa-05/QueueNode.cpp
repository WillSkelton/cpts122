#include "QueueNode.h"

QueueNode::QueueNode(Data &newData) {
	this->data = new Data(newData);
	this->next = nullptr;
}

QueueNode::QueueNode(int customerNumber, int serviceTime, int totalTime) {
	this->data = new Data(customerNumber, serviceTime, totalTime);
	this->next = nullptr;
}

// DTOR
QueueNode::~QueueNode() {
	delete this->data;
	delete this->next;
}

// Getters
Data * QueueNode::getData(void) {
	return this->data;
}

QueueNode * QueueNode::getNextNode(void) {
	return this->next;
}

// Setters
void QueueNode::setData(Data *newData) {
	this->data = newData;
}

void QueueNode::setNext(QueueNode *newNode) {
	this->next = newNode;
}
