#include <iostream>
#include <string>


using std::string;

class Node {

public:
	// CTOR
	Node(char letter, string morse);

	// CCTOR
	Node(const Node &src);

	// DTOR
	~Node();

	// Getters
	char getLetter(void);
	string getMorse(void);
	
	Node * getLeft(void);
	Node * getRight(void);

	// Setters
	void setLeft(Node *newLeft);
	void setRight(Node *newRight);


private:
	
	char letter;
	string morse;

	Node *leftNode;
	Node *rightNode;

};


