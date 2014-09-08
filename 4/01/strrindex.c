#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t);

int main()
{
	printf("%d\n", strrindex("hello world", 'w'));

	return 0;
}

int strrindex(char s[], char t)
{
	for (int i = strlen(s); i > 0; --i)
		if (s[i] == t)
			return i;
	return -1;
}
