#include <stdio.h>
#include <string.h>

void itoa(int, char[], int);
void recurse(int given, char dest[], int base, int sign);
void reverse(char[]);

int main()
{
	int testInt = 432;
	char testStr[1000];

	printf("Given integer: %d\n", testInt);
	itoa(testInt, testStr, 0);
	printf("%s\n", testStr);
	return 0;
}

void itoa(int given, char dest[], int base)
{
	int sign = 0;
	if (given < 0) {
		// -
		sign = 1;
		given *= -1;
	}
	recurse(given, dest, base, sign);
	reverse(dest);
}

void recurse(int given, char dest[], int base, int sign)
{
	dest[base++] = given % 10 + '0';
	if (given > 9) {
		given /= 10;
		recurse(given, dest, base, sign);
	} else {
		if (sign)
			dest[base++] = '-';
	}
}

void reverse (char s[])
{
	char c;
	int i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
