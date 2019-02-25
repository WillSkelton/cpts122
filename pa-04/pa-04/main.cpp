#include "plan.h"

int main(void) {


	time_t myTime = time(NULL);

	string str = ctime(&myTime);
	
	cout << str.substr(8,2) << endl;

	return 0;
}

