#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct BinTree {
  char name[10];
  int value;
  struct BinTree* left;
  struct BinTree* right;
} BinTree;


typedef struct LinkedList {
  int value;
  struct LinkedList* rest;
} LinkedList;

int rest(int n) {
  return n - 1;
}

void countdown(int n) {
  if (n == 0) {
    printf("0\n");
  } else {
    printf("%d ", n);
    countdown(rest(n));
  }
}

void countdownEven(int n) {
  if (n == 0) {
    printf("0\n");
  } else {
    if (n % 2 == 0) {
      printf("%d ", n);
    }
    countdownEven(rest(n));
  }
}

int sumEven(int n) {
  if (n == 0) {
    return 0;
  } else {
    if (n % 2 == 0) {
      return n + sumEven(rest(n));
    } else {
      return sumEven(rest(n));
    }
  }
}


int sum(LinkedList* head) {
  if (head == NULL) {
    return 0;
  } else {
    int countSelf = head->value;
    int countRest = sum(head->rest);
    return countSelf + countRest;
  }
}


bool isAllPositive(LinkedList* head) {
  if (head == NULL) {
    return true;
  } else {
    if (head->value > 0) {
      return isAllPositive(head->rest);
    } else {
      return false;
    }
  }
}

bool isAllPositiveLessReadableButShorterWithALongerFunctionName(LinkedList* head) {
  return (head == NULL) 
    || ((head->value > 0) && isAllPositiveLessReadableButShorterWithALongerFunctionName(head->rest));
}


void printList(LinkedList* head) {
  if (head == NULL) {
    //do nothing
  } else {
    printf("%d -> ", head->value);
    printList(head->rest);
  }
}


void printListReverse(LinkedList* head) {
  if (head == NULL) {
    //do nothing
  } else {
    printListReverse(head->rest);
    printf("%d -> ", head->value);
  }
}

void doubleList(LinkedList* head) {
  if (head == NULL) {
    // do nothing
  } else {
    /* head->value = head->value * 2; */
    head->value *= 2;
    doubleList(head->rest);
  }
}

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
    recursive call for next
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


char firstChar(char word[]) {
  return word[0];
}

char lastChar(char word[], int length) {
  return word[length - 1];
}

char* middle(char word[]) {
  return word + 1;
}

void printWord(char word[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%c", word[i]);
  }
  printf("\n");
}


bool isPalindrome(char word[], int length) {
  printWord(word, length);

  if (length == 0 || length == 1) {
    return true;
  } else {
    if (firstChar(word) != lastChar(word, length)) {
      return false;
    } else {
      return isPalindrome(middle(word), length - 2);
    }
  }
}


int main() {
  countdown(10);
  countdownEven(10);

  printf("%s %s a palindrome\n", "MADAM", isPalindrome("MADAM", strlen("MADAM")) ? "is" : "is not");

  LinkedList a = {3, NULL};
  LinkedList b = {-4, &a};
  LinkedList c = {2, &b};
  LinkedList d = {1, &c};

  printf("Sum: %d\n", sum(&d));
  printf("isAllPositive: %d\n", isAllPositive(&d));
  printf( isAllPositiveLessReadableButShorterWithALongerFunctionName(&d) ? "All positive!\n" : "Not all positive!\n");
  
  printList(&d);
  printf("\n");
  printListReverse(&d);
  printf("\n");
  //1 -> 2 -> -4 -> 3 ->
  //3 -> -4 -> 2 -> 1 -> 


  // BinTree* bt1 = NULL;
  // BinTree bt = NULL; // can't assign NULL to struct

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
