#include <stdio.h>

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
void my_strncmp(char *s, char *t, int n);

int main()
{
  char s1[1000] = "hello world";
  char t1[1000] = "mine pooh pooh";
  int n = 4;

  my_strncpy(s1, t1, n);
  printf("%s\n", s1);

  char s2[1000] = "hello world";
  char t2[1000] = "mine pooh pooh";

  my_strncat(s2, t2, n);
  printf("%s\n", s2);

  return 0;
}


void my_strncpy(char *s, char *t, int n)
{
  while (n > 0) {
    *s++ = *t++;
    n--;
  }
  *s = '\0';
}

void my_strncat(char *s, char *t, int n)
{
  while (*s != '\0')
    s++;

  while (n > 0) {
    *s++ = *t++;
    n--;
  }
}

void my_strncmp(char *s, char *t, int n)
{
}
