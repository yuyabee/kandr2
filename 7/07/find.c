#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

//Modify the pattern find_from_fileing program of Chapter 5 to take its input from a set of named files or, if no files are named as arguments, from the standard input. Should the file name be printed when a matching line is found?


int main(int argc, char *argv[])
{
  // ./a.out pattern file_names
  char *prog = argv[0];
  char *pat = argv[1];
  void find_from_file(char *, char *);

  if (argc == 2) {
    // temp
    exit(1);
  } else {
    argc--;
    argv++;
    argv++;
    while (--argc > 0)
      find_from_file(pat, *argv++);
  }

  return 0;
}

void find_from_file(char *pattern, char *filename)
{
  FILE *fp;
  char line[MAXLINE];
  int count = 1;
  printf("processing %s ...\n", filename);
  if ((fp = fopen(filename, "r")) != NULL) {
    while (fgets(line, MAXLINE, fp) != NULL) {
      if ((strstr(line, pattern) != NULL))
        printf("In %s: line: %d %s", filename, count, line);
      count++;
    }
    fclose(fp);
  } else {
    fprintf(stderr, "find: couldn't read file: %s\n", filename);
    exit(0);
  }
}
