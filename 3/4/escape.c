#include <stdio.h>

// copy t to s
void escape(char s[], char t[]);

int main() {
	char t[50] = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
	char s[50];
	escape(s, t);
	printf("%s", t);
	printf("%s", s);
}

void escape(char s[], char t[]) {
	int j;
	for (int i = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				break;
			case '\a':
				s[j++] = '\\';
				s[j] = 'a';
				break;
			case '\b':
				s[j++] = '\\';
				s[j] = 'b';
				break;
			default:
				s[j] = t[i];
				break;
		}
		j++;
	}
	s[j] = '\0';
}
