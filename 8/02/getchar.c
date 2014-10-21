#include <stdio.h>
#include "unistd.h"

int main()
{
  char c;
  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
