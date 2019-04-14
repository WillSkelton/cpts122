#include "BST.h"

#include <fstream>

using std::fstream;
using std::ios;
using std::getline;

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
	string translateFile(void);


	// Fill File
	void fillTree(void);

	// to upper case
	string toUpper(string str);

private:

	BST *morseTable;

};