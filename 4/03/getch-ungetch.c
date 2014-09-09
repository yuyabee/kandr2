#include <stdio.h>
#include <ctype.h>

#define NUMBER  '0'

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	// skip if c is a sign
	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	i = 0;
	// this c is inserted to s[0] in the first while statement that stoped the
	// loop
	if (c == '-') {
		// if next is not a digit, '-' is binary operation, but not a sign
		if (!isdigit(s[++i] = c = getch())) {
			ungetch(c);
			return c;
		}
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
