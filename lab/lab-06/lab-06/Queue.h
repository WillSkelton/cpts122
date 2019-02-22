#pragma once
#include <iostream>
#include <string>
using namespace std;

class Queue {

private:
	class Node {
	
	public:
		Node(string str);
		//~Node();
		
		string getString();
		//string setString(string newStr);
		
		Node *next;

	private:
		string str;
	};

	int length;

	Node *head;
	Node *tail;
	
public:
	Queue();
	Queue(string str);
	~Queue();


	int getLength(void);
	void enqueue(string newStr);
	void dequeue(void);

	void printQueueL2R(void);

	void printQueueL2RRec(Node *node);
	Node* getHead(void);



};

