#include <stdio.h>

int main()
{
  int a[10] = {1,2,3,4,5,6,7};
  int *pa = &a[0];
  int x = *(pa+1);

  printf("%d\n", x);

  return 0;
}
