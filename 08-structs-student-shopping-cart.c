#include <string.h>

typedef struct {
  char code[20];
  char desc[100];
  int units;
} Subject;

typedef struct {
  char name[30];
  int studentNum;
  char course[10];
  Subject favSubj;
} Student;

int main() {
  Subject cmsc11 = {"CMSC11", "Introduction to Computer Science using C", 3};
  Student mel = {"Mel Joseph", 201555555, "BSCS", cmsc11};

  strcpy(cmsc11.desc, "Introduction to Computer Science using Python"); 
  return 0;
}

typedef struct {
  int code;
  char desc[30];
  float price;
} Item;

typedef struct {
  Item item;
  int quantity;
} ShoppingItem;

typedef struct {
  int itemCount;
  ShoppingItem items[100];
} ShoppingCart;


float shoppingItemCost(ShoppingItem item) {
  return item.item.price * item.quantity;
}

float totalCost(ShoppingCart cart) {
  float total;
  for (int i = 0; i < cart.itemCount; i++) {
    total += shoppingItemCost(cart.items[i]);
  }
  return total;
}


