#include <stdio.h>

/*
   structure is defined above all functions so it is global.
 */

struct employee
{
  char name[20];
  int age;
  char doj[10];   // date of joining
  char designation[20];
};
// Function argument is pointer. So we can change original data. But data is protected to writing by const. Only reading.
void print_struct(const struct employee *);

int main() {
  struct employee dev = {"Jane", 25, "25/2/2015", "Developer"};
  print_struct(&dev);

  return 0;
}

void print_struct(const struct employee *ptr) {
  printf("Name: %s\n", ptr->name);
  printf("Age: %d\n", ptr->age);
  printf("Date of joining: %s\n", ptr->doj);
  printf("Age: %s\n", ptr->designation);

  ptr->age = 11;
  printf("Age: %d\n", ptr->age);

  printf("\n");
}
