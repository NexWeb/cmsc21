#include <string.h>
#include <stdio.h>

typedef struct {
  char code[20];
  char desc[100];
  int units;
} Subject;

typedef struct {
  char name[30];
  int studentNum;
  char course[10];
  Subject* favSubj;
} Student;


typedef struct {
  int code;
  char desc[30];
  float price;
} Item;

typedef struct {
  Item* item;
  int quantity;
} ShoppingItem;


typedef struct {
  int itemCount;
  ShoppingItem items[100];
} ShoppingCart;


float shoppingItemCost(ShoppingItem item) {
  return item.item->price * item.quantity;
}

float totalCost(ShoppingCart cart) {
  float total = 0;
  for (int i = 0; i < cart.itemCount; i++) {
    total += shoppingItemCost(cart.items[i]);
  }
  return total;
}



int main() {
  Subject cmsc11 = {"CMSC11", "Introduction to Computer Science using C", 3};
  Student mel = {"Mel Joseph", 201555555, "BSCS", &cmsc11};

  Subject* cmsc11ptr = &cmsc11;

  strcpy(cmsc11.desc, "Introduction to Computer Science using Python"); 
  
  printf("%s\n", cmsc11.desc);
  printf("%s\n", (*cmsc11ptr).desc);
  printf("%s\n", cmsc11ptr->desc);

  /* printf("%s\n", mel.(*favSubj).desc); */
  printf("%s\n", (*(mel.favSubj)).desc);
  printf("%s\n", mel.favSubj->desc);

  Item soap = {1, "Soap", 25.0};
  ShoppingItem si1 = {&soap, 2};

  ShoppingCart sc = {1, {si1}};

  printf("%s\n", sc.items[0].item->desc);
  printf("%p\n", sc.items[0].item);

  return 0;
}

