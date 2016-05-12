#include <stdio.h>
#include <stdlib.h>

#define RESIZE 5

typedef struct {
  int* nums;
  int size;
  int length;
} ArrayList;


ArrayList createArrayList(int size) {
  ArrayList list;
  list.nums = calloc(size, sizeof(int));
  list.size = size;
  list.length = 0;
  return list;
}

void addElement(ArrayList* list, int el) {
  if (list->length == list->size) {
    int newSize = list->size + RESIZE;

    int* newArray = realloc(list->nums, newSize * sizeof(int));
    if (newArray != NULL) {
      // point to new array
      list->nums = newArray;
      list->size = newSize;
    }

    /* // alloc new array */
    /* int* newArray = calloc(newSize, sizeof(int));  */
    /*  */
    /* // copy data from old to new */
    /* for (int i = 0; i < list->length; i++) { */
    /*   newArray[i] = list->nums[i]; */
    /* } */
    // don't forget to free!
    /* free(list->nums); */
    /* list->nums = newArray; */

  }

  if (list->size > list->length) {
    list->nums[list->length] = el;
    list->length++;
  }
}


int* createArray(int size) {
  /* int* nums = malloc(size * sizeof(int)); */
  int* nums = calloc(size, sizeof(int));
  if (nums == NULL) {
    return NULL;
  }
  return nums;
}

void displayArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void initArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    arr[i] = i;
  }
}


int* createInt(int n) {
  int* intPtr = malloc(sizeof(int));
  *intPtr = n;
  return intPtr;
}

typedef struct { 
  char name[20];
  int age;
} Student;

int main() {
  ArrayList list = createArrayList(5);
  addElement(&list, 3);
  addElement(&list, 4);
  addElement(&list, 6);
  addElement(&list, 7);
  addElement(&list, 8);
  addElement(&list, 9);
  addElement(&list, 9);
  addElement(&list, 9);
  addElement(&list, 9);
  addElement(&list, 9);
  addElement(&list, 9);
  displayArray(list.nums, list.length);

  int* numPtr = createInt(5);
  printf("%d\n", *numPtr);

  int* arr = createArray(5);
  /* initArray(arr, 5); */
  displayArray(arr, 5);

  printf("%lu\n", sizeof(int));
  printf("%lu\n", sizeof(float));
  printf("%lu\n", sizeof(unsigned int));
  printf("%lu\n", sizeof(Student));

  return 0;
}
