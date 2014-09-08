#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(const char string[]);
int isHexa(const char c);
int hexaMapInt(const char c);

int main() {
	printf("0x7E equals to %d in decimal\n", htoi("0x7E"));

	return 0;
}

int htoi(const char s[]) {
	int i, res;

	if (s[0] != '0' || s[1] != 'x') {
		printf("hexadecimal must start with 0x");
		return 0;
	}

	i = 2;
	res = 0;
	while (isHexa(s[i]) && s[i] != '\0') {
		if (isdigit(s[i]))
			res = res * 16 + s[i] - '0';
		else
			res = res * 16 + hexaMapInt(s[i]);
		++i;
	}

	return res;
}

int isHexa(const char c) {
	return isdigit(c) || c >= 'A' || c <= 'F';
}

int hexaMapInt(const char c) {
	if (c == 'A')
		return 10;
	else if (c == 'B')
		return 11;
	else if (c == 'C')
		return 12;
	else if (c == 'D')
		return 13;
	else if (c == 'E')
		return 14;
	else if (c == 'F')
		return 15;

	return 0;
}
