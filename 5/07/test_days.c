#include <stdio.h>
#include "days.c"

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

int main()
{
  printf("%d\n", day_of_year(2014, 9, 24));
  return 0;
}
