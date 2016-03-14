#include <stdio.h>

int convertCharToNumeric(char ch) {
  if ('0' <= ch && ch <= '9') {
    return ch - '0';
  } else if ('A' <= ch && ch <= 'C') {
    return 2;
  } else if ('D' <= ch && ch <= 'F') {
    return 3;
  //...
  } else {
    return 9;
  }
}

int append(int num, int x) {
  return (num * 10) + x;
}

// char[] -> int
// Accepts an alphanumeric phone number and
// returns the number converted to numeric
int convertToNumeric(char alpha[]) {
  int result = 0;
  for(int i = 0; alpha[i] != '\0'; i++) {
    int numeric = convertCharToNumeric(alpha[i]);
    result = append(result, numeric);
  }
  return result;
}

int main() {
  printf("%d = 2436373\n", convertToNumeric("243NERD")); // expect 2436373
  return 0;
}
