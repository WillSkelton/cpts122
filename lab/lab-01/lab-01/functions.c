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

void partTwo(void) {
	char myString[17] = "My name is Will.";

	char *token;

	token = myStringToke(myString, ' ');
	
	while (token != NULL) {
		printf("%s\n", token);
		token = myStringToke(myString, ' ');
	}

	//printf("%s\n", mystring);

	//mystringtoke(mystring, ' ');
	//printf("%s\n", mystring);

}

char* myStringToke(char *str, char del) {
	static int idx = 0;
	char *tokePointer = NULL;

	while(str[idx] != '\0') {
		if (str[idx] == del) {
			str[idx] = '\0';
			++idx;
			tokePointer = &str[idx];
			//subString[i + 1] = '\0';
			break;
		}
		++idx;
	}
	return tokePointer;
	
}