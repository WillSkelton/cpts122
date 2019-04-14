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
	bool addNode(const Node);

	// Print Tree
	void printTreeA2Z(void);



private:
	Node *root;

};

