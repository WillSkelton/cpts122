#pragma once
#include "Node.h"

using namespace std;

class Queue {

public:

	Queue();
	~Queue();

	bool enqueue(string);

private:

	Node *head;
	Node *tail;

	int length;

};
