#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
char *lookupdefn(char *s);
struct nlist *install(char *, char *);
void undef(char *);

int main()
{
  char *testNames[] = {"test1", "test2", "test3"};
  char *testDefns[] = {"test1val", "test2val", "test3val"};

  for (int i = 0; i < 3; i++)
    printf("Next exists if it is 1: %d\n", (install(testNames[i], testDefns[i])->next == NULL) ? 0 : 1);

  printf("Name: %s, Defn: %s\n", testNames[0], lookupdefn("test1"));

  struct nlist *np3 = lookup("test3");
  printf("Name: %s, Defn: %s\n", testNames[2], lookupdefn("test3"));

  undef("test2");

  printf("test2 should not exist 0: %s\n", lookupdefn("test2"));
  return 0;
}

unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  // to ensure the value is less than HASHSIZE
  return hashval % HASHSIZE;
}

struct nlist *
lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0) {
      printf("s: %s\n", s);
      return np;
    }
  return NULL;
}

char *
lookupdefn(char *s)
{
  struct nlist *np = lookup(s);
  if (np != NULL)
    return np->defn;
  else
    return "not defined";
}

struct nlist *
install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else
    free((void *) np->defn);
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

void undef(char *name)
{
  struct nlist *np = lookup(name);
  np->name = np->defn = NULL;
}
