
#include "List.h"


int main(void) {

	List<string> students;

	students.print();

	Data *d1 = new Data(1, 1, "D1", "Email@email.com", 12, "Architecture", 0, 0);
	Data *d2 = new Data(2, 2, "D2", "Email@email.com", 14, "CS", 2, 4);
	Data *d3 = new Data(3, 3, "D3", "Email@email.com", 17, "Ecology", 2, 15);

	d1->getAbsences()->push("4/20/2019");
	d2->getAbsences()->push("4/21/2019");
	d3->getAbsences()->push("4/22/2019");

	

	students.prepend(d1);
	students.print();
	cout << endl;

	students.prepend(d2);
	students.print();
	cout << endl;

	students.prepend(d3);
	students.print();
	cout << endl;

	students.reportTwo(5);
	cout << endl;

	students.reportOne();



	return 0;
}