#include <stdio.h>

int power(int, int);

int main() {
	int i;

	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));

	return 0;
}

int power(int m, int n) {
	int ret = 1;
	for (int i = 1; i <= n; ++i)
		ret *= m;
	return ret;
}
