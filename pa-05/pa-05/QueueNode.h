#include "Data.h"

class QueueNode {
public:
	// CTORS
	// QueueNode();
	QueueNode(Data &newData);
	QueueNode(int customerNumber, int serviceTime, int totalTime);

	// DTOR
	~QueueNode();

	// Getters
	Data * getData(void);
	QueueNode * getNextNode(void);

	// Setters
	void setData(Data *newData);
	void setNext(QueueNode *newNode);

	

private:
	Data *data;
	QueueNode *next;
};