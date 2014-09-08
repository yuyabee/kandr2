#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
	char x[20] = "hello world";
	squeeze(x, "ho");
	printf("squeeze \"hello world\" with \"ho\": %s\n", x);

	return 0;
}

void squeeze(char s1[], char s2[]) {
	int i, j, k, mark;

	mark = 0;
	for (i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k])
				mark = 1;
		if (!mark)
			s1[j++] = s1[i];

		mark = 0;
	}

	s1[j] = '\0';
}
