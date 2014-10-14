#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  char c;

  if (strcmp(argv[1], "lower") == 0)
    while ((c = getchar()) != EOF)
      putchar(tolower(c));
  else if (strcmp(argv[1], "upper") == 0)
    while ((c = getchar()) != EOF)
      putchar(toupper(c));
  else
    printf("only accepts lower or upper");
}
