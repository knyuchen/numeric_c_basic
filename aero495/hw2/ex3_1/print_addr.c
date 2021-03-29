#include <stdio.h>
#include <math.h>

int main () {
   int x = 1;
   int y = 2;
   int z = 3;
   
   int*x_ptr = &x;

   ++(*x_ptr);

   z = *x_ptr;

   ++(*x_ptr);

   int*ptr = &y;

   *ptr = *x_ptr + z;

   printf("%d, %d, %d \n", x, y, z);

   return 0;
}
