#include <stdio.h>
#include <stdbool.h>

typedef struct {
  char name[20];
  int age;
  int studentNumber;
} Student;

typedef struct {
  int x; 
  int y;
} Point;

/*
typedef struct {
  int x1;
  int y1;
  int x2;
  int y2;
} Line;
*/

typedef struct {
  Point a;
  Point b;
} Line;

/*
typedef struct {
  Point a;
  Point b;
  Point c;
  Point d;
} Poly;
*/

typedef struct {
  Line a;
  Line b;
} Poly;

/* float distance(int x1, int y1, int x2, int y2) */

float distance(Point a, Point b) {
  return 0;
}

/* bool isParallel(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) */

bool isParallel(Line a, Line b) {
  /* return ... a.a.x a.a.y a.b.x a.b.y */
  /*   b.a.x b.a.y b.b.x b.b.y; */
  return false;
}

/*
bool isOverlapping(
    int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
    int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8
)
*/

bool isOverlapping(Poly a, Poly b) {
  return false;
}

Point translate(Point a, int x, int y) {
  /* Point newPoint = a; */
  /* newPoint.x += x; */
  /* newPoint.y += y; */
  /* return newPoint; */

  a.x = 10;
  a.y = 20;

  return (Point) {a.x + x, a.y + y};
}

void displayPoint(Point a) {
  printf("Point: %d %d\n", a.x, a.y);
}

int main() {
  Point a = {1, 2};

  /* a.x = 1; */
  /* a.y = 2; */

  Point b;

  b.x = 3;
  b.y = 5;

  Line l1 = {a, b};
  /* Line l1 = {a, {3, 3}}; */

  /* l1.a = a; */
  /* l1.b = b; */

  a.x = 5;
  a.y = -3;

  printf("a: %d %d\n", a.x, a.y);
  printf("l1: %d %d, %d %d\n", l1.a.x, l1.a.y, l1.b.x, l1.b.y);

  displayPoint(translate(a, 3, 6));

  printf("a: %d %d\n", a.x, a.y);




  int x = 1;
  int y = x;

  Line l2;

  Student george;

  return 0;
}
