#include <iostream>

#include "QueueNode.h";

using std::cout;
using std::cin;	
using std::endl;
using std::string;

class Queue {
public:
	// CTORS
	Queue(string name);
	Queue(Data &newData, string name);
	Queue(QueueNode &newNode, string name);
	
	// CCTOR
	Queue(Queue &src);

	// DTOR
	~Queue();

	// Getters
	int getLength(void);
	QueueNode * getHead(void);
	QueueNode * getTail(void);

	void incOrDecLength(int modifier);
	//void setHead(QueueNode *newHead);
	//void setTail(QueueNode *newTail);
	

	string name;


	// Queue Methods
	bool enqueue(Data &newData);
	bool dequeue(void);
	bool printQueue(void);
	bool printQueue(string tag);

	
private:
	int length;
	QueueNode *head;
	QueueNode *tail;
};