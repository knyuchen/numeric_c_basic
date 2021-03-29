#include <stdio.h>
#include <math.h>

int* f (int p) {
   int n = p;
   int*x = &n;
   return x;
//   return &n;
//   printf ("%p \n\n", &x);

}


int main () {
   int* u = f(5);
   int* v = f(10);
//   printf ("%p \n\n", u);
//   printf ("%p \n\n", v);
   printf ("%d \n\n", *u);
//   printf ("%p \n\n", u);
//   printf ("%p \n\n", v);


   return 0;
}
