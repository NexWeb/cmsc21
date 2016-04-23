#include <stdio.h>
#include <math.h>

typedef struct BinTree {
  char name[10];
  int value;
  struct BinTree* left;
  struct BinTree* right;
} BinTree;

/* stub
int maxSales(BinTree root) {
  return 0;
}
*/

/*
int maxSales(BinTree root) {
  if (base case) {
    do something
  } else {
    do something for current
    recursive call
  }
}
*/
int pop(BinTree* root) {
  if (root == NULL) {
    return 0;
  } else {
    int countSelf = 1;
    int countLeft = pop(root->left);
    int countRight = pop(root->right);
    return countSelf + countLeft + countRight;
  }
}

int maxSales(BinTree* root) {
  if (root == NULL) {
    return 0;
  } else {
    int salesLeft = maxSales(root->left);
    int salesRight = maxSales(root->right);
    return fmax(fmax(root->value, salesLeft), salesRight);
  }
}

int numLevels(BinTree* root) {
  if (root == NULL) {
    return 0;
  } else {
    return 1 + fmax(numLevels(root->left), numLevels(root->right));
  }
}


void forever(int count) {
  printf("In forever: %d\n", count);
  forever(count + 1);
  printf("Exiting forever");
}


int main() {
  BinTree* bt1 = NULL;

  BinTree jean = {"Jean", 24, NULL, NULL}; 
  BinTree jeane = {"Jeane", 27, NULL, NULL}; 
  BinTree icel = {"Icel", 10, NULL, NULL}; 
  BinTree candace = {"Candace", 48, &jean, &jeane}; 
  BinTree lovely = {"Lovely", 9, &icel, NULL}; 
  BinTree honey = {"Honey", 40, &lovely, NULL}; 
  BinTree jj = {"JJ", 3, &honey, &candace}; 

  printf("Population: %d\n", pop(&jj));
  printf("Max sales: %d\n", maxSales(&jj));
  printf("Num levels: %d\n", numLevels(&jj));

  
  return 0;
}
