#include "Data.h"

template<class T>
class Node {
public:
	// CTOR, DTOR, Getters, Setters...
	Node();
	Node(Data *data);
	Node(int recordNumber, int ID, string name, string email, int units, string program, string year, int numAbsences);



	~Node();

	Node<T> * getNext(void);
	void setNext(Node<T> *node);

	Data *getData(void);

private:
	Data *data;
	Node<T> *next;

};

template<class T>
Node<T>::Node(){
	this->data = nullptr;
	this->next = nullptr;
}

template<class T>
Node<T>::Node(int recordNumber, int ID, string name, string email, int units, string program, string year, int numAbsences){
	Data *newRecord = new Data(recordNumber, ID, name, email, units, program, year, numAbsences);
	this->data = newRecord;
	this->next = nullptr;
}
template<class T>
Node<T>::Node(Data *data) {

	this->data = data;
	this->next = nullptr;

}


template<class T>
Node<T>::~Node(){
	delete this->data;
	delete this->next;

}

template<class T>
Node<T> * Node<T>::getNext(void){
	return this->next;
}

template<class T>
void Node<T>::setNext(Node<T> *node){
	this->next = node;
}

template<class T>
Data * Node<T>::getData(void) {
	return this->data;
}
