#include "BST.h"

// CTOR
BST::BST() {
	this->root = nullptr;
}

// DTOR
BST::~BST() {
	delete this->root;
}

// Lookup
string BST::lookup(char letter) {
	return this->lookup(this->root, letter);

}

string BST::lookup(Node *root, char letter) {
	string morse = "";

	if (root == nullptr) {
		morse = "error";
	}
	else if (root->getLetter() == letter) {
		morse = root->getMorse();
	}
	else if (root->getLetter() < letter) {
		morse = lookup(root->getRight(), letter);
	}
	else {
		morse = lookup(root->getLeft(), letter);
	}

	return morse;
}



// Add Node
bool BST::addNode(char letter, string morse) {
	return this->addNode(this->root, letter, morse);
}

bool BST::addNode(Node *tree, char letter, string morse) {
	bool success = false;

	// Empty Tree
	if (tree == nullptr) {
		this->root = new Node(letter, morse);
		success = true;
	}
	else {
		if (letter < tree->getLetter()) {
			if (tree->getLeft() != nullptr) {
				addNode(tree->getLeft(), letter, morse);
			}
			else {
				Node *temp = new Node(letter, morse);
				tree->setLeft(temp);

			}
		}
		else if (letter > tree->getLetter()) {
			if (tree->getRight() != nullptr) {
				addNode(tree->getRight(), letter, morse);
			}
			else {
				Node *temp = new Node(letter, morse);
				tree->setRight(temp);
			}
		}
		else {
			cout << "duplicate: " << letter << endl;
		}
	}

	return success;
}


// Print Tree
void BST::printTreeInOrder(void) {
	printTreeInOrder(this->root);
}

void BST::printTreeInOrder(Node *tree) {
	if (tree == nullptr) {
		return;
	}

	printTreeInOrder(tree->getLeft());
	cout << tree->getLetter() << endl;
	printTreeInOrder(tree->getRight());
}