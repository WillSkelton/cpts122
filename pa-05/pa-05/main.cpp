#include "Queue.h"

int main(void) {

	Data d1 = Data(1, 10, 20);
	Data d2 = Data(2, 20, 40);
	Data d3 = Data(3, 30, 60);
	Data d4 = Data(4, 40, 80);
	Data d5 = Data(5, 50, 100);

	Queue myQueue = Queue(d1);
	myQueue.printQueue();

	cout << endl << "D2" << endl << endl;;

	myQueue.enqueue(d2);
	myQueue.printQueue();

	cout << endl << "D3" << endl << endl;;

	myQueue.enqueue(d3);
	myQueue.printQueue();

	cout << endl << "Dequeue D3" << endl << endl;;

	myQueue.dequeue();
	myQueue.printQueue();

	return 0;
}