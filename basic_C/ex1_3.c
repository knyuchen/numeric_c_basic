#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main () {


   int k;
   float * array;
   printf ("Please enter size of array \n");

   scanf ("%d", &k);

   array = malloc(k*sizeof(float));
   

   int i;

   for (i = 0; i < k; i = i + 1) {
      printf ("Please enter number for index %d \n", i);
      scanf ("%f", &array[i]);
   }

   printf ("Please enter a index \n");
   scanf ("%d", &i);
   if (i > k-1 || i < 0) {
      printf ("Invalid Index \n");
   }
   else {
      printf ("%f \n", array[i]);
   }
   return 0;
}
