#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP   100
#define NUMBER  '0'

int getop(char []);
void push(double);
double pop(void);
void showTop(void);
void showStat(void);
void swapTopStack(void);
void clearStack(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				//printf("%g\n", atof(s));
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					// this doesn't work since the numbers are double
					// push(pop() % op2);
					// instead, use <math.h> fmod
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;
			// print top element of the stack
			case 'T':
				showTop();
				break;
			case 'S':
				swapTopStack();
				break;
			case 'C':
				clearStack();
				break;
			case '\n':
				showStat();
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
