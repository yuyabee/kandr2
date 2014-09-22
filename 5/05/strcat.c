#include <stdio.h>

void my_strcat(char *s, char *t);

int main()
{
  char hello[1000] = "hello, ";
  char world[1000] = "world\n";

  printf("%s\n", hello);
  my_strcat(hello, world);
  printf("%s\n", hello);

  return 0;
}

void my_strcat(char *s, char *t)
{
  while (*s != '\0')
    s++;

  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}
