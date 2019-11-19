#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
union types {
  float f;
  int i;
};

int main(int argc,
         char *argv[]) {
  union types t;

//	t.i=500;
  t.f = 5.4;

  printf("%d\n",t.i);
  return 0;
}
