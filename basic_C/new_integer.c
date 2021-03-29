#include <stdio.h>
#include <math.h>

int* new_integer (void) {
   int x = 3;
   printf ("%p \n\n", &x);
   return &x;
}


int main () {
   int* a = new_integer();

   printf ("%p \n\n", a);
   printf ("%d \n\n", *a);


   return 0;
}
