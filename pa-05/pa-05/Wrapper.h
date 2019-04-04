

#include "Queue.h"

class Wrapper {
public:

	Wrapper();

	~Wrapper();

	void REPL(void);
	int printMenu(void);

	void runSimulation(void);

	// Tests
	bool runAllTests(void);
	bool basicTest(void);

private:
	Queue *normal;
	Queue *express;

	int timeElapsed;

};