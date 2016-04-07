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

int main() {
  
  float* fptr;
  float f;
  isValid(&f);
  /* isValid(*f); */

  int x = 2;
  int y = 3;

  printf("%p\n", minimum(&x, &y));
  printf("%d\n", *minimum(&x, &y));
  return 0;
}
