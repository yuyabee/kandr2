#include <stdio.h>
#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>

// allow read and write to every users
#define PERMS 0666
#define BUFSIZ 1024

int main(int argc, char *argv[])
{
  int f1, f2;
  int n;
  char buff[BUFSIZ];

  if (argc != 3) {
    printf("cp: Usage cp from to\n");
    exit(1);
  }
  if ((f1 = open(argv[1], O_RDONLY, PERMS)) == -1) {
    printf("cp: could not open %s\n", argv[0]);
    exit(1);
  }
  if ((f2 = creat(argv[2], PERMS)) == -1) {
    printf("cp: could not create %s with permission %d\n", argv[2], PERMS);
  }

  if ((n = read(f1, buff, BUFSIZ)) > 0)
    if (write(f2, buff, n) != n) {
      printf("cp: something went wrong while writing to %s\n", argv[2]);
      exit(1);
    }

  // exit will close the files opened during the execution
  exit(0);
}
