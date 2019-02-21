#include "Node.h"

Node::Node(string &name) {
	itemName = name;
	next = nullptr;
}

Node:: ~Node() {
	delete next;
}