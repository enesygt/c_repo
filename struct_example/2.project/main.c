#include <stdio.h>

/*
   structure is defined above all functions so it is global.
 */

struct player
{
  char name[20];
  float height;
  float weight;
  float fees;
};

void print_struct(struct player p);
struct player deduct_fees(struct player p);

int main() {
  struct player p = {"Joe", 5.9, 59, 5000 };
  print_struct(p);
  p = deduct_fees(p);
  print_struct(p);

  return 0;
}

struct player deduct_fees(struct player p) {
  p.fees -= 1000;
  return p;
}

void print_struct(const struct player p) {
  printf("Name: %s\n", p.name);
  printf("Height: %.2f\n", p.height);
  printf("Weight: %.2f\n", p.weight);
  printf("Fees: %.2f\n", p.fees);

  printf("\n");
}
