#include <stdio.h>

float celsius(float fahr) {
	return 5.0 * (fahr - 32.0) / 9.0;
}

int main() {
	float fahr = 0;
	int step = 20;

	printf("fahr\tcelsius\n");
	while (fahr <= 300) {
		printf("%3.1f\t%6.1f\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
}
