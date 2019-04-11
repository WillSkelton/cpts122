

#include "Queue.h"
#include <assert.h>

class Wrapper {
public:

	Wrapper();

	~Wrapper();

	void REPL(void);
	int printMenu(void);

	void runSimulation(int duration);

	void cleanQueues(void);

	// Tests
	bool enqueueEmptyQueueTest(void);

	bool enqueueQueueTest(void);

	bool dequeueOneNodeQueue(void);

	bool dequeueTwoNodeQueue(void);

	bool yeeHawTest(void);

	bool basicTest(void);

	bool runAllTests(void);

private:
	Queue *normal;
	Queue *express;

	int timeElapsed;
};