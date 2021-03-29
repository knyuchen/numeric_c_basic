#include <stdio.h>
#include <math.h>

int factorial (int x) {
   if ( x < 0) {
      printf ("Error: input number is %d and is negative \n\n", x);
      return 0;
   }
   else if (x == 0) {
      return 1;
   }
   else {
      return x*factorial(x-1);
   }
}


int main () {
   int num_in;
   int factorial_out;
/*  
   num_in = 0;
   factorial_out = factorial(num_in);
   if (factorial_out != 0) {
      printf ("input number is %d, factorial of input number = %d \n\n", num_in, factorial_out);
   }
   
   num_in = 10;
   factorial_out = factorial(num_in);
   if (factorial_out != 0) {
      printf ("input number is %d, factorial of input number = %d \n\n", num_in, factorial_out);
   }
 

   num_in = -2;
   factorial_out = factorial(num_in);
   if (factorial_out != 0) {
      printf ("input number is %d, factorial of input number = %d \n\n", num_in, factorial_out);
   }
*/ 

   return 0;
}
