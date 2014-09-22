#define ALLOCSIZE 10000

// buffer
static char allocbuf[ALLOCSIZE];

// pointer to next free position
static char *allocp = allocbuf;
// static char *allocp = &allocbuf[0];

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    // update to point next free position
    allocp += n;
    return allocp - n;
  } else
    // C guarantees that zero is never a valid address for data
    return 0;
}

void afree(char *p)
{
  // allocbuf is pointing the first element of allocbuf
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
