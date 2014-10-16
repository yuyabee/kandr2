#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
  FILE *f1, *f2;
  void diff(FILE *, FILE *);

  if (argc < 3) {
    fprintf(stderr, "%s: too few arguments given", argv[0]);
    exit(1);
  }
  if ((f1 = fopen(argv[1], "r")) != NULL && (f2 = fopen(argv[2], "r")) != NULL) {
    diff(f1, f2);
    fclose(f1);
    fclose(f2);
  } else {
    fprintf(stderr, "%s: couldn't read one of %s, %s", argv[0], argv[1], argv[2]);
    exit(1);
  }

  return 0;
}

void diff(FILE *f1, FILE *f2)
{
  char l1[MAXLINE], l2[MAXLINE];
  int count = 1;

  while (fgets(l1, MAXLINE, f1) != NULL && fgets(l2, MAXLINE, f2) != NULL) {
    if (strcmp(l1, l2) != 0) {
      printf("At line %d:\n\n%s\n%s\n", count, l1, l2);
      exit(0);
    }
    count++;
  }
}
