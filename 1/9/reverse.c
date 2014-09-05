#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char s[]);

int main() {
	int len, i;
	char line[MAXLINE], longest[MAXLINE];

	while ((len = getLine(line, MAXLINE)) != 0) {
		if (len > 1) {
			reverse(line);
			printf("%s\n", line);
		}
	}

	return 0;
}

int getLine(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[]) {
	int i, j;
	char tmp;

	for (i = 0; s[i] != '\0'; ++i)
		;
	--i;
	for (j = 0; j < i; ++j) {
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		--i;
	}
}
