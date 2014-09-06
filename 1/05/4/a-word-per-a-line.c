#include <stdio.h>

#define IN	0
#define OUT	0

int main() {
	int c, state;

	state = OUT;

	for (c = 0; c != EOF; c = getchar()) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			printf("\n");
		}
		else if (state == OUT) {
			state = IN;
			putchar(c);
		}
	}
}
