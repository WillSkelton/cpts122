

#include "Queue.h"
#include <assert.h>

class Wrapper {
public:

	// ctor
	Wrapper();

	//dtor
	~Wrapper();

	// Main menu loop
	void REPL(void);

	// Prints menu options
	int printMenu(void);

	// runs the simulation
	void runSimulation(int duration);

	// completely whipes the queues in between simulations
	void cleanQueues(void);

	// Tests
	// tests enqueue on a queue with no nodes
	bool enqueueEmptyQueueTest(void);

	// tests enqueue on a queue with 1 node
	bool enqueueQueueTest(void);

	// tests dequeue on a queue with 1 node
	bool dequeueOneNodeQueue(void);

	// tests dequeue on a queue with 2 nodes
	bool dequeueTwoNodeQueue(void);

	// Runs test for 24 hrs. WARNING: TAKES A VERY LONG TIME TO RUN
	bool yeeHawTest(void);

	bool basicTest(void);
	
	// Runs all tests
	bool runAllTests(void);

private:
	Queue *normal;
	Queue *express;

	int timeElapsed;
};