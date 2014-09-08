#include <stdio.h>

int my_strpbrk(char s1[], char s2[]);

int main() {
	char a[20] = "winnie the pooh";
	char b[20] = "ol";

	printf("%d\n", my_strpbrk(a, b));

	char c[20] = "b";
	printf("%d\n", my_strpbrk(a, c));
	return 0;
}

int my_strpbrk(char s1[], char s2[]) {
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
	return -1;
}
