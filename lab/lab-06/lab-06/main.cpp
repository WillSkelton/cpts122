#include "Queue.h"

int main(void) {


	Queue myQueue = Queue("Stuff");


	myQueue.enqueue("My");
	myQueue.enqueue("name");
	myQueue.enqueue("is");
	myQueue.enqueue("Will");


	myQueue.printQueueL2RRec(myQueue.getHead());


	return 0;

}