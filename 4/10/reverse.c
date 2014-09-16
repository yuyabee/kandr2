#include <stdio.h>
#include <string.h>

void reverse(char[]);
void reverseRec(char[], int, int);
void swap(char[], int, int);

int main()
{
	char testStr[1000] = "hello world";
	printf("Input: %s\n", testStr);
	reverse(testStr);
	printf("reversed: %s\n", testStr);

	return 0;
}

void reverse(char str[])
{
	reverseRec(str, 0, strlen(str) - 1);
}

void reverseRec(char str[], int b, int e)
{
	if (b < e) {
		swap(str, b++, e--);
		reverseRec(str, b, e);
	}
}

void swap(char str[], int a,int b)
{
	char tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;
}
