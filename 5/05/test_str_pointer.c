#include <stdio.h>

int main()
{
  char *hello_world = "Hello World\n";
  char *p_hello_world;

  p_hello_world = hello_world;
  p_hello_world += 1;

  printf("%s", p_hello_world);
  printf("%s", hello_world);

  return 0;
}
