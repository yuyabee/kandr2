#include <stdio.h>

int strend(char *s, char *t);

int main()
{
  char a[1000] = "poooh san\n";
  char b[1000] = "san\n";
  char c[1000] = "poooh";
  char d[1000] = "oh";

  int one, two, three;
  one = strend(a, b);
  two = strend(a, c);
  three = strend(c, d);

  printf("%d\n", one);
  printf("%d\n", two);
  printf("%d\n", three);

  return 0;
}

int strend(char *s, char *t)
{
  char *ps = s;
  char *pt = t;

  while (*s != '\0')
    s++;
  while (*t != '\0')
    t++;

  while (s >= ps && t >= pt) {
    if (*t != *s)
      return 0;
    s--;
    t--;
  }

  return 1;
}
