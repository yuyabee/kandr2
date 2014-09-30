#include <stdio.h>

int main(int argc, char *argv[])
{
  while (--argc > 0)
    printf("%s%s", *++argv, (argc > 1) ? " " : ""); /* if it's not last argument, add " " */
  printf("\n");

  return 0;
}
