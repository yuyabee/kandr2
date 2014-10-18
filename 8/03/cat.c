#include <stdio.h>
#include <fcntl.h>

#define PERM 0666

int main(int argc, char *argv[])
{
  int n;
  int buf[BUFSIZ];

  int read(char *, int, int);
  int write(char *, int, int);

  while (argc > 0) {
    if ((n = read(*argv++, buf, PERM)) != -1)
      write(stdout, buf, n);
  }
}
