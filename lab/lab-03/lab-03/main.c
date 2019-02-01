#include "functions.h"

int main(void) {

	Stack A;
	newStack(&A);
	A.name = 'A';

	Stack B;
	newStack(&B);
	B.name = 'B';


	Stack C;
	newStack(&C);
	C.name = 'C';


	Data d1 = { 1.0 };
	Data d2 = { 2.0 };
	Data d3 = { 3.0 };
	Data d4 = { 4.0 };

	Data *tower[] = {
		&d1,
		&d2,
		&d3,
		&d4
	};

	batchPush(&A, tower, 4);
	
	peek(&A);

	hanoi(&A, &B, &C, 4);


	peek(&A);
	peek(&B);
	peek(&C);


	return 0;
}