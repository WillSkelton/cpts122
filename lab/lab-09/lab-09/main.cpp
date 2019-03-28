// This example illustrates how to define a Stack class template.

#include "TestStack.h"

//#include <vector>

int main(void)
{
	int item1 = -89, item2 = 104;
	string str = "5  6  2 *  + 9  /";
	//	vector<int> my_vector; // vector<> is from the Standard Template Library (STL)

	TestStack<int> tester;

	//tester.Test(item1, item2);
	tester.testPostfix(str);

	return 0;
}