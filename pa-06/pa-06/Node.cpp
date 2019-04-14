#include "Node.h"


// CTOR
Node::Node(char letter, string morse) {
	this->letter = letter;
	this->morse = morse;

	this->leftNode = nullptr;
	this->rightNode = nullptr;

}

// CCTOR
Node::Node(const Node &src) {
	this->letter = src.letter;
	this->morse = src.morse;

	this->leftNode = src.leftNode;

	this->rightNode = src.rightNode;
}

// DTOR
Node::~Node() {

	delete this->leftNode;
	delete this->rightNode;

}

// Getters
char Node::getLetter(void) {
	return this->letter;
}

string Node::getMorse(void) {
	return this->morse;
}

Node * Node::getLeft(void) {
	return this->leftNode;
}

Node * Node::getRight(void) {
	return this->rightNode;
}


// Setters
void Node::setLeft(Node *newLeft) {
	this->leftNode = newLeft;
}

void Node::setRight(Node *newRight) {
	this->rightNode = newRight;
}

