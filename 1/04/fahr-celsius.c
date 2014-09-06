#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

int main() {
	int fahr;

	for (fahr = 0; fahr <= UPPER; fahr += 20) {
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}
