#include <stdio.h>
#include <stdbool.h>

int* minimum(int* x, int* y) {
  if (*x < *y) {
    return x;
  } else {
    return y;
  }
}

bool isValid(float* fptr) {
  return false;
}

int* maxOf2(int* a, int* b) {
  if (*a > *b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  
  float* fptr;
  float f;
  isValid(&f);
  /* isValid(*f); */

  int x = 2;
  int y = 3;

  printf("%p\n", minimum(&x, &y));
  printf("%d\n", *minimum(&x, &y));


  int* xptr = &x;
  printf("%d\n", x);
  printf("%d\n", *xptr);

  maxOf2(xptr, &y);




  return 0;
}
