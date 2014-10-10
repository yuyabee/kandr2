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
struct nlist *install(char *, char *);
void undef(char *);

int main()
{
  char *testNames[] = {"test1", "test2", "test3"};
  char *testDefns[] = {"test1val", "test2val", "test3val"};

  for (int i = 0; i < 3; i++)
    printf("Next exists if it is 1: %d\n", (install(testNames[i], testDefns[i])->next == NULL) ? 0 : 1);

  struct nlist *np1 = lookup("test1");
  printf("Name: %s, Defn: %s\n", np1->name, np1->defn);

  struct nlist *np3 = lookup("test3");
  printf("Name: %s, Defn: %s\n", np3->name, np3->defn);

  undef("test2");

  printf("test2 should not exist 0: %d\n", (lookup("test2") == NULL) ? 0 : 1);
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
    if ((strcmp(s, np->name)) == 0)
      return np;
  return NULL;
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
