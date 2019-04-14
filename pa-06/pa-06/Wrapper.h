#include "BST.h"
#include <fstream>

class Wrapper {

public:
	// CTOR
	Wrapper();


	// DTOR
	~Wrapper();


	// REPL
	void REPL(void);

	// Translate
	string translate(string message);

	// Fill File
	void fillTree(void);

private:

	BST *morseTable;

};