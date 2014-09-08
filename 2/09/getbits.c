#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main() {
	printf("%d\n", getbits(372, 5, 4));
	return 0;
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n) & ~(~0 << n));
}
