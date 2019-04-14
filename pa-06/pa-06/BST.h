#include "Node.h"


using std::cout;
using std::cin;
using std::endl;

class BST {

public:
	// CTOR
	BST();

	// DTOR
	~BST();

	// Lookup
	string lookup(const char srcLetter);

	// Add Node
	bool addNode(char letter, string morse);
	bool addNode(Node *tree, char letter, string morse);

	// Print Tree
	void printTreeInOrder(void);
	void printTreeInOrder(Node *tree);

private:
	Node *root;

};

