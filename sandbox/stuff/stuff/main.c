#include <stdio.h>


void test(int arr[], int length) {
	printf("length: %d | sizeof: %d\n", length, sizeof(length));

	int *num = malloc(10);
	long num2 = *num;

	int newArr[sizeof(num2)] = { 0 };
	printf("length: %d \n", length);

}

int main(void) {

	int array[9] = { 0, 7, 2, 3, 10, 4, 9, -1, 6 };

	test(array, 9);

	return 0;
}