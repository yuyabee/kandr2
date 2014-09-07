#include <stdio.h>

int my_strlen(char string[]);

int main() {
	char test[20] = "hello world";

	printf("length of \"hello world\" is: %d\n", my_strlen(test));

	return 0;
}

int my_strlen(char s[]) {
	int i;

	while (s[i] != '\0')
		++i;

	return i;
}
