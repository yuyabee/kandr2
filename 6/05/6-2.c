#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define MAXGROUPWORD 100
#define GROUPINGBASE 6

int getch(void);
void ungetch(int c);
int getword(char *, int);
int isalpha(int);
int isalnum(int);
int isspace(int);
int isvariable(int);
char *my_strdup(char *);

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct gnode {
  // first 6 characters
  char *word;
  int count;
  struct tnode *list[MAXGROUPWORD];
  struct gnode *next;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);

struct gnode *addgroup(struct gnode *, struct tnode *);
struct gnode *addgroupbase(struct gnode *, struct tnode *);
void groupprint(struct gnode *);
struct gnode *galloc(void);

int main(int argc, char *argv[]) {
  struct tnode *troot = NULL;
  struct gnode *groot = NULL;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      troot = addtree(troot, word);
  printf("Printing tree root: ");
  treeprint(troot);

  groot = galloc();
  groot->word = "";
  groot->list[0] = NULL;
  groot->count = 0;
  groot->next = NULL;

  addgroup(groot, troot);
  printf("Group print: ");
  groupprint(groot);

  return 0;
}

void groupprint(struct gnode *p)
{
  if (p != NULL) {
    printf("%4d %s\n", p->count, p->word);
    treeprint(*p->list);
    groupprint(p->next);
  }
}

  struct gnode *
addgroup(struct gnode *g, struct tnode *t)
{
  if (g != NULL) {
    addgroup(g, t->left);
    addgroupbase(g, t);
    addgroup(g, t->right);
  }

  return g;
}

  struct gnode *
addgroupbase(struct gnode *g, struct tnode *t)
{
  char *str = my_strdup(t->word);
  str[GROUPINGBASE] = '\0';

  if (g == NULL) {
    g = galloc();
    g->word = str;
    g->count = 1;
    g->list[0] = t;
    g->next = NULL;
  } else if ((strncmp(g->word, t->word, GROUPINGBASE)) == 0) {/* using strncmp to compare only arbitary number of characters */
    g->list[g->count] = t;
    g->count++;
  } else
    g->next = addgroupbase(g->next, t);
  return g;
}

  struct gnode *
galloc(void)
{
  return (struct gnode *) malloc(sizeof(struct gnode));
}

void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

  struct tnode *
addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0) /* strcmp return negative value if the first char* is smaller */
    p->left = addtree(p->left, w);
  else
    p-> right = addtree(p->right, w);
  return p;
}

  struct tnode *
talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

  char *
my_strdup(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}

int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];
char bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
