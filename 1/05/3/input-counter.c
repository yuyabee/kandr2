#include <stdio.h>

int main() {
	int c, nl, nb, nt;

	nl = 0;
	nb = 0;
	nt = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == '\t')
			++nt;
		if (c == ' ')
			++nb;
	}

	printf("NewLine\t%d\n", nl);
	printf("Tabs\t%d\n", nt);
	printf("Blanks\t%d\n", nb);
}
