#include <stdio.h>

int main() {
	printf("%d\n", 372 & 404); // 276
	printf("%d\n", 372 | 404); // 500
	printf("%d\n", 372 ^ 404); // 224
	printf("%d\n", 372 << 2);  // 1488
	printf("%d\n", 372 >> 2);  // 93

	printf("%d\n", ~1);

	return 0;
}
