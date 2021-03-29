#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {
   int a = 35;
   int *b = &a;
   int ** c = &b;
   int d = 42;
   int* e = &d;
   int** f = &e;
   int* t1 = b;
   int** t2 = f;
  
   b = e;
   e = t1;
   f = c;
   c = t2;

   printf("a is %d, *b is %d, **c is %d\n", a, *b, **c);
   printf("d is %d, *e is %d, **f is %d\n", d, *e, **f);
   return 1;
}
