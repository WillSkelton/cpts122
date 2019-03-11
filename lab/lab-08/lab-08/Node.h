#pragma once
#include <iostream>

using std::string;

class Node {
public:
	// CTOR
	Node(string newStr);

	// CCTOR
	Node(const Node &src);

	// DTOR
	~Node();

	// Getters
	Node * getLeft(void);
	Node * getRight(void);
	string * getString(void);

	// Setters
	void setLeft(Node *newNode);
	void setRight(Node *newNode);
	void setString(string newString);


private:
	// Children
	Node *leftPtr;
	Node *rightPtr;

	// Value
	string *str;
};

// CTOR
Node::Node(string newStr) {
	this->leftPtr = nullptr;
	this->rightPtr = nullptr;

	this->str = new string(newStr);

}

// CCTOR
Node::Node(const Node &src) {
	this->str = new string(*src.str);
}

// DTOR
Node::~Node() {
	delete this->str;
}

// Getters
 
Node * Node::getLeft(void) {
	return this->leftPtr;
}

 
Node * Node::getRight(void) {
	return this->rightPtr;
}

 
string * Node::getString(void) {
	return this->str;
}

// Setters
void Node::setLeft(Node *newNode) {
	this->leftPtr = newNode;
}

 
void Node::setRight(Node *newNode) {
	this->rightPtr = newNode;
}

 
void Node::setString(string newStr) {
	delete this->str;

	this->str = new string(newStr);
}
