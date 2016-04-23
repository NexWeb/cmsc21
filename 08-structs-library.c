


typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  char title[100];
  int numDays;
} Title;

typedef struct {
  Title* title;
  Date borrowedDate;
  Date returnedDate;
} Book;


typedef struct {
  char type;
  Book borrowedBooks[10];
  int numBorrowed;
} Borrower;

int main() {
  /* Borrow - 'S', "TC7", borrowed 19 4 2016, returned 21 4 2016, numDays 1 */
  Title tc7Title = {"TC7", 1};

  Title* tc7ptr = &tc7Title;

  Date yest = {19, 4, 2016};
  Date tom = {21, 4, 2016};

  /* Book tc7 = {&tc7Title, yest, tom}; */
  Book tc7 = {tc7ptr, yest, tom};

  Borrower bob = {'S', {tc7}, 1};
  calculateDues(bob);
  return 0;
}
