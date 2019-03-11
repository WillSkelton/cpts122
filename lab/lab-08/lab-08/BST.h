#pragma once
#include "Node.h"

class BST {
public:
	// CTOR
	BST();

	// DTOR
	~BST();

	// GET
	Node * getRoot(void);
	int getSize(void);

	// POST
	void insertNode(Node * node, string *str);

private:
	
	int depth;
	int breadth;
	int size;
	
	Node *root;

};


// CTOR
BST::BST() {
	this->root = nullptr;

	this->depth = 0;
	this->size = 0;
	this->breadth = 0;

}

// DTOR
BST::~BST() {
	delete this->root;
}

// GET
Node * BST::getRoot(void) {
	return this->root;
}
int BST::getSize(void) {
	return this->size;
}

// POST
void BST::insertNode(Node * node, string *str) {
	if (node == nullptr) {
		this->root = new Node(*str);
	}
}
