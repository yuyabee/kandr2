#include <stdio.h>

int bitcount(unsigned);

int main() {
	printf("%d\n", bitcount(372));

	return 0;
}

int bitcount(unsigned x) {
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;

	return b;
}
