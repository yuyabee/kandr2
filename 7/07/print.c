#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

// Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file.

int main(int argc, char *argv[])
{
  void print(char *, char *, int);
  char *prog = argv[0];
  if (argc < 2) {
    printf("%s: need names of file\n", prog);
    exit(1);
  } else {
    int page = 1;
    argv++;
    while (--argc > 0) {
      print(prog, *argv++, page);
      page++;
    }
  }
}

void print(char *prog, char *filename, int page)
{
  FILE *fp;
  char line[MAXLINE];
  if ((fp = fopen(filename, "r")) != NULL) {
    printf("PAGE: %d\nTITLE: %s\n", page, filename);
    printf("--------------------------------------\n");
    while (fgets(line, MAXLINE, fp))
      printf("%s", line);
    printf("--------------------------------------\n");
  } else {
    printf("%s: couldn't open %s\n", prog, filename);
    exit(1);
  }
}
