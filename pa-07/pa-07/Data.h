#include "Stack.h"




class Data {

public:
	// Ctor:
	Data();
	Data(int recordNumber, int ID, string name, string email, int units, string program, int year, int numAbsences, Stack *absences);

	// Dtor
	~Data();
	
	// Getters
	int getRecordNumber(void);
	int getID(void);
	string getName(void);
	string getEmail(void);
	int getUnits(void);
	string getProgram(void);
	string Data::getYear(void);
	int getNumAbsences(void);
	Stack *getAbsences(void);

	void setRecordNumber(int);
	void setID(int);
	void setName(string);
	void setEmail(string);
	void setUnits(int);
	void setProgram(string);
	void setYear(string year);
	void setNumAbsences(int);

private:
	// Records
	int recordNumber; // (max 3 digits)
	int ID; // (max 9 digits)
	string name; // (last, first)
	string email;
	int units; // (number of credits for class or AU for audit)
	string program; // (major)
	string year;
	// Extra
	int numAbsences;
	Stack *absences;

};


