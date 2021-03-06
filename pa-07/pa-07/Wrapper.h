#include "List.h"

class Wrapper {

public:

	// CTOR
	Wrapper();

	// DTOR
	~Wrapper();

	// Start App
	void startApp(void);

private:
	void REPL(void);

	int inputCheck(int lower, int upper);

	void router(int choice);

	void openFiles(void);

	void closeFiles(void);

	void printMenu(void);

	void read(fstream &infile, string filename);

	void import(void);

	void load(void);

	void store(void);

	void markAbsences(void);

	void generateReports(void);

	
	fstream infile;
	fstream report1;
	fstream report2;
	fstream masterFile;

	List<string> classList;


	
};