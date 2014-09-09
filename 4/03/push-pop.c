#include <stdio.h>

#define MAXVAL  100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}

void showStat(void)
{
	if (sp > 0)
		printf("Stack stat: %g\n", val[sp - 1]);
	else
		printf("error: stack empty\n");
}

void showTop(void)
{
	if (sp > 0)
		printf("Top of the Stack is: %g\n", val[sp - 1]);
	else
		printf("error: stack empty\n");
}
