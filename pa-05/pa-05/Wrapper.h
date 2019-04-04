

#include "Queue.h"

class Wrapper {
public:

	Wrapper();

	~Wrapper();

	void REPL(void);
	int printMenu(void);

	void runSimulation(int duration);

	void cleanQueues(void);

	// Tests
	bool runAllTests(void);
	bool basicTest(void);

private:
	Queue *normal;
	Queue *express;

	int timeElapsed;

};