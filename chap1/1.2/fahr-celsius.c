#include <stdio.h>

int celsius(int fahr) {
	return 5 * (fahr - 32) / 9;
}

int main() {
	int fahr = 0;
	int step = 20;

	printf("fahr\tcelsius\n");
	while (fahr <= 300) {
		printf("%3d\t%6d\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
}
