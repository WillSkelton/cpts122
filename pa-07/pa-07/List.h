#include "Node.h"

template <class T>
class List {

public:
	// CTOR
	List();

	// DTOR
	~List();

	// Prepend
	bool prepend(Data *record);

	// Print
	void print();

	// All Students and their Absences Report
	void reportOne(void);

	// Abcences Threshold Report
	void reportTwo(void);

	// Get Length
	int getLength(void);

	Node<T> * getHead(void);

private:

	Node<T> *head;

	int length;
	

};

// CTOR
template <class T>
List<T>::List(){

	this->length = 0;
	this->head = nullptr;

}

// DTOR
template <class T>
List<T>::~List(){

	delete this->head;

}

// Prepend
template <class T>
bool List<T>::prepend(Data *record){

	Node<T> *temp = new Node<T>(record);

	if (this->head != nullptr) {
		temp->setNext(this->getHead());
	}


	this->head = temp;

	return true;

}

// Print
template <class T>
void List<T>::print(){

	Node<T> *temp = this->head;

	while (temp != nullptr) {

		cout << temp->getData()->getName() << ": " << temp->getData()->getProgram() << endl;

		temp = temp->getNext();
	}

}

// All Students and their Absences Report
template <class T>
void List<T>::reportOne(void){}

// Abcences Threshold Report
template <class T>
void List<T>::reportTwo(void){}

// Get Length
template <class T>
int List<T>::getLength(void){
	return this->length;
}

template <class T>
Node<T> * List<T>::getHead(void){
	return this->head;
}
