#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point pt1, struct point ptw);
int ptinrect(struct point p, struct rect r);

int main()
{
  struct point testpoint = makepoint(4, 3);
  struct rect testrect;
  testrect.pt1 = makepoint(2, 1);
  testrect.pt2 = makepoint(5, 4);
  printf("%d\n", ptinrect(testpoint, testrect));
}

struct point makepoint(int x, int y)
{
  struct point temp;

  temp.x = x;
  temp.y = y;

  return temp;
}

struct point addpoint(struct point pt1, struct point pt2)
{
  pt1.x += pt2.x;
  pt1.y += pt2.y;
  return pt1;
}

int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}
