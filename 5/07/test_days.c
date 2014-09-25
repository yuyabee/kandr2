#include <stdio.h>
#include "days.c"

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

int main()
{
  int m, d;
  printf("%d\n", day_of_year(2014, 9, 24));
  month_day(2014, 60, &m, &d);
  printf("%d/%d\n", m, d);

  return 0;
}
