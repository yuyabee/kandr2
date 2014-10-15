#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main()
{
  int age;
  char *name;

  minscanf("%d %s", &age, name);
  printf("%s(%d)\n", name, age);

  return 0;
}

void minscanf(char *fmt, ...)
{
  va_list ap;
  char *sval, *p;
  int *ival;
  float *fval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%')
      continue;
    switch (*++p) {
      case 'd':
        ival = va_arg(ap, int *);
        scanf("%d", ival);
        break;
      case 's':
        sval = va_arg(ap, char *);
        scanf("%s", sval);
        break;
      case 'f':
        fval = va_arg(ap, float *);
        scanf("%f", fval);
        break;
      default:
        break;
    }
  }
}
