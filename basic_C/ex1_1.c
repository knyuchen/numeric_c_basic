#include <stdio.h>
#include <math.h>



int main () {

   float array[3];


   printf ("Please enter 3 numbers \n");

   int i;

   for (i = 0; i < 3; i = i + 1) {
      printf ("Please enter number for index %d \n", i);
      scanf ("%f", &array[i]);
   }

   printf ("Please enter a index \n");
   scanf ("%d", &i);
   if (i > 2 || i < 0) {
      printf ("Invalid Index \n");
   }
   else {
      printf ("%f \n", array[i]);
   }
   return 0;
}
