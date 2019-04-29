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
	void print2File(fstream &outfile);
	void print2File(fstream &outfile, Node<T> *head);


	// All Students and their Absences Report
	void reportOne(fstream &outfile);

	// Abcences Threshold Report
	void reportTwo(int threshold, fstream &outfile);

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
	this->length++;

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

template <class T>
void List<T>::print2File(fstream &outfile) {
	outfile << ",ID,Name,Email,Units,Program,Level" << endl;
	this->print2File(outfile, this->head);

}

template <class T>
void List<T>::print2File(fstream &outfile, Node<T> *head) {


	if (head == nullptr) {
		return;
	}

	print2File(outfile, head->getNext());

	outfile << head->getData()->getRecordNumber() << ","
		<< head->getData()->getID() << ","
		<< "\"" << head->getData()->getName() << "\","
		<< head->getData()->getEmail() << ","
		<< head->getData()->getUnits() << ","
		<< head->getData()->getProgram() << ","
		<< head->getData()->getProgram() << ","
		<< head->getData()->getYear() << endl;

	/*while (temp != nullptr) {
		outfile << temp->getData()->getRecordNumber() << ","
			<< temp->getData()->getID() << ","
			<< "\"" << temp->getData()->getName() << "\","
			<< temp->getData()->getEmail() << ","
			<< temp->getData()->getUnits() << ","
			<< temp->getData()->getProgram() << ","
			<< temp->getData()->getProgram() << ","
			<< temp->getData()->getYear() << endl;
		temp = temp->getNext();
	}*/
}


// All Students and their Absences Report
template <class T>
void List<T>::reportOne(fstream &outfile){
	Node<T> *temp = this->head;

	while (temp != nullptr) {

		cout << temp->getData()->getName() << ": " << temp->getData()->getAbsences()->peek() << endl;
		outfile << temp->getData()->getName() << ": " << temp->getData()->getAbsences()->peek() << endl;

		temp = temp->getNext();
	}
}

// Absences Threshold Report
template <class T>
void List<T>::reportTwo(int threshold, fstream &outfile) {

	Node<T> *temp = this->head;

	while (temp != nullptr) {

		if (temp->getData()->getNumAbsences() <= threshold) {

			cout << temp->getData()->getName() << ": " << temp->getData()->getProgram() << endl;
			outfile << temp->getData()->getName() << ": " << temp->getData()->getProgram() << endl;


		}
		temp = temp->getNext();

	}

}

// Get Length
template <class T>
int List<T>::getLength(void){
	return this->length;
}

template <class T>
Node<T> * List<T>::getHead(void){
	return this->head;
}
