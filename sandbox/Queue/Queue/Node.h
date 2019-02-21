#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	Node(string &name);
	
	~Node();

private:
	string itemName;

	Node *next;
	
	
};