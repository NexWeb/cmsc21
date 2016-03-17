#include <stdio.h>

int only3Square(int table[3][3]) {
  return table[2][2];
}

/* int isSquare(int rowLen, int colLen, int table[rowLen][colLen]) { */
/*   return 0; */
/* } */

int isSquare(int rowLen, int colLen, int** table){
/* int isSquare(int rowLen, int colLen, int table[rowLen][colLen]) { */
  for (int i = 0; i < rowLen; i++) {
    for (int j = 0; i < colLen; j++) {
      // do something 
    }
  }
}

int main() {
  int table10[4][4] = {
    1, 2, 3, 4,
    1, 2, 3, 4,
    1, 2, 3, 4,
    1, 2, 3, 4
  };

  printf("%d\n", only3Square(table10));

     
                      
  int nums[5];
  int nums1[5] = {1, 2, 3, 4, 5};
  int nums2[] = {1, 2, 3, 4, 5};
  /* int nums3[]; */

  int table[2][3];
  int table1[2][3] = {{1, 1, 1}, {2, 2, 2}};
  /*
  int table2[2][3] = {1, 1, 1, 2, 2, 2};
  int table3[][];
  int table4[2][];
  int table5[][3];
  */

  int table6[][2] = {1, 2}; // for 3x2 don't think so
  /* int table7[3][] = {1, 2, 3}; */
  int table8[][2] = {1, 2, 3, 4, 5, 6};
  int table9[][2] = {{1, 2}, {3, 4}};

  return 0;
}
