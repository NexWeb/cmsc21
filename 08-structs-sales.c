#include <stdio.h>


typedef struct {
  char name[30];
  int population;
} Region;

typedef struct {
  int duration; // in months
  Region* region;
} Assignment;

typedef struct {
  int assignCount;
  Assignment assignments[3];
} SalesRep;

float avePop(SalesRep sr) {
  int total = 0;
  for (int i = 0; i < sr.assignCount; i++) {
    total += sr.assignments[i].region->population;
  }
  return (float) total / sr.assignCount;
}

int main() {
  Region r7 = {"Central Visayas", 6800180};
  Region r8 = {"Western Visayas", 4195000};

  Assignment asgn1 = {24, &r7};
  Assignment asgn2 = {12, &r8};

  SalesRep sr = {2, {asgn1, asgn2}};

  printf("%f\n", avePop(sr));

  r8.population = 4195001;

  printf("%.2f\n", avePop(sr));

  return 0;
}
