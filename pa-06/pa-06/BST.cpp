#include "BST.h"


/************************************ CREDITS: **********************************************************
CREDIT TO ANDY O'FALLON: I spent a lot of time looking at his example code to get these methods working. *
While this is my work, it would've taken much longer without his help so I can't not give him credit.   *
********************************************************************************************************/

// CTOR
BST::BST() {
	this->root = nullptr;
}

// DTOR
BST::~BST() {
	delete this->root;
}

// Lookup

// Helper function to reduce arguments to make the function more semantic
string BST::lookup(char letter) {
	return this->lookup(this->root, letter);

}

// recursive function to find a node of a BST
string BST::lookup(Node *root, char letter) {
	string morse = "";

	// If character isn't found, prints error
	if (root == nullptr) {
		morse = "error";
	}

	// if the letter given is the same as the one we're looking at, get the translation
	else if (root->getLetter() == letter) {
		morse = root->getMorse();
	}

	// if the letter given is greater than the letter we're looking at, loo to the right first
	else if (root->getLetter() < letter) {
		morse = lookup(root->getRight(), letter);
	}

	// if right didn't work out, look left
	else {
		morse = lookup(root->getLeft(), letter);
	}

	return morse;
}



// Add Node
// Helper function to reduce arguments to make the function more semantic
bool BST::addNode(char letter, string morse) {
	return this->addNode(this->root, letter, morse);
}

// Adds a node to the BST. CREDIT: Andy O'Fallon
bool BST::addNode(Node *tree, char letter, string morse) {
	bool success = false;

	// Empty Tree
	if (tree == nullptr) {
		// Just add the node right to the root;
		this->root = new Node(letter, morse);
		success = true;
	}
	// tree has stuff in it...
	else {
		// if the letter we're adding is less than the letter we're looking at
		if (letter < tree->getLetter()) {
			// Check if we're at a left leaf
			if (tree->getLeft() != nullptr) {
				// we aren't so we go left
				addNode(tree->getLeft(), letter, morse);
			}
			else {
				// we are at a left leaf so we put it here
				Node *temp = new Node(letter, morse);
				tree->setLeft(temp);

			}
		}
		// the letter we're adding is greater than the one we're looking at so it goes to the right
		else if (letter > tree->getLetter()) {
			// Check if we're at a right leaf
			if (tree->getRight() != nullptr) {
				// we are not so we go right
				addNode(tree->getRight(), letter, morse);
			}
			else {
				// we are so we put the letter here
				Node *temp = new Node(letter, morse);
				tree->setRight(temp);
			}
		}
		// if the letter we're trying to add is neither greater than not less than, it's a duplicate
		else {
			cout << "duplicate: " << letter << endl;
		}
	}

	return success;
}


// Print Tree
// Helper function to reduce arguments to make the function more semantic
void BST::printTreeInOrder(void) {
	printTreeInOrder(this->root);
}

// Prints tree in ASCII order. CREDIT: Andy O'Fallon
void BST::printTreeInOrder(Node *tree) {

	// if we're at the end of tree, return
	if (tree == nullptr) {
		return;
	}

	// goes all the way left
	printTreeInOrder(tree->getLeft());

	// prints the node
	cout << tree->getLetter() << endl;

	// goes right
	printTreeInOrder(tree->getRight());
}