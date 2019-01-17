#include "functions.h"

void partOne(void) {
	char str1[1] = { '\0' };
	char str2[8] = "String2";
	char str3[5] = "Str3";


	printf("Before: %s | ", str2);
	stringReverse(str2, 0, sizeof(str2) - 2);
	printf("After: %s\n", str2);

	printf("Before: %s | ", str3);
	stringReverse(str3, 0, sizeof(str3) - 2);
	printf("After: %s\n", str3);

	
}

char* stringReverse(char *str, int idx, int size) {
	
	char c = str[idx];
	str[idx] = str[size - idx];
	str[size - idx] = c;
	
	if (idx == size / 2) {
		return str;
	}

	stringReverse(str, idx + 1, size);
}